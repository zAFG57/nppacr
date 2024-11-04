#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
#ifndef FRAME_H
#define FRAME_H
#include "frame.hpp"
#endif
#ifndef SUBFRAME_H
#define SUBFRAME_h
#include "subframe.hpp"
#endif
#include <thread>
#include <future>
#include <iostream>
using namespace std;


Frame::Frame() {
    this->nbPts = 0;
    this->subFrame = {};
    this->nbThread = thread::hardware_concurrency();
    this->nbPtsNotUpdate=0;
}

Frame::~Frame() {}

void Frame::ajouterPoint(Point* point) {
    if (this->lastPts != nullptr) {
        this->lastPts->setSuivant(point);
    }
    this->lastPts = point;
    this->nbPts ++;
    this->nbPtsNotUpdate ++;
    this->updateSubFrame();
}

void Frame::updateSubFrame() {
    if(this->nbPts ==1) {
        this->subFrame.push_back(this->lastPts);
        return;
    }
    int sbSize = this->subFrame.size();
    if (sbSize<this->nbThread) { // on doit ajouter des subframes
        this->nbPtsNotUpdate = 0;
        if (sbSize*this->minSizeSubFrame < nbPts) {
            this->subFrame.push_back(this->lastPts);
        }
        return;
    }
    // on doit allonger les subframes
    if (this->nbPtsNotUpdate != this->nbThread) return;
    for (int i=0; i<sbSize; i++) {
        int nbSuiv = i;
        Point* pts = this->subFrame.at(i);
        for (int y=nbSuiv; y>0; y--) {
            pts = pts->getSuivant();
        }
        this->subFrame.at(i) = pts;
    }
    this->nbPtsNotUpdate = 0;
}

SubFrame* Frame::getsubframe(int index) {
    if (index>=this->subFrame.size()) return nullptr;
    Point* ptsStop;
    int nbPts = (this->nbPts - this->nbPtsNotUpdate)/this->nbThread;
    if (index == this->nbThread-1 || index == this->subFrame.size()-1) {
        ptsStop = nullptr;
        nbPts +=  this->nbPtsNotUpdate;
    } else {
        ptsStop = this->subFrame.at(index+1);
    }
    Point* ptsStart;
    ptsStart = this->subFrame.at(index);
    return new SubFrame(ptsStart,ptsStop,nbPts);
}

vector<Point*> Frame::getNPlusProche(Point* pts, int nbPts) {
    vector<vector<Point*>> preselection;
    vector<thread> coeur;
    vector<SubFrame*> subFrames;
    vector<future<vector<Point*>>> futures;
    vector<Point*> ptsCandida;
    int i;
    for (i=0; i<this->nbThread; i++) {
        subFrames.push_back(this->getsubframe(i));
        if (subFrames.at(i) == nullptr) break;
        promise<vector<Point*>> prom;
        futures.push_back(prom.get_future());
        coeur.emplace_back([sub = subFrames.at(i), pts, nbPts, prom = move(prom)]() mutable {
            prom.set_value(getPtsSubFrame(sub, pts, nbPts));
        });
    }
    i--;
    for (i=i; i>0; i--) {
        if (subFrames.at(i) != nullptr) {
            coeur.at(i).join();
        }
    }
    for (i=i; i<this->nbThread; i++) {
        if (subFrames.at(i) == nullptr) break;
        vector<Point*> a = futures.at(i).get();
        ptsCandida.insert(ptsCandida.end(),a.begin(),a.end());
    }
    return solveNPlusProche(pts,ptsCandida,nbPts);
}

vector<Point*> getPtsSubFrame(SubFrame* sub, Point* pts, int nbPts) {
    return sub->getNPlusProche(pts,nbPts);
}