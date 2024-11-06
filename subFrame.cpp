#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
#ifndef SUBFRAME_H
#define SUBFRAME_h
#include "subframe.hpp"
#endif
#ifndef MAIN_H
#define MAIN_H
#include "main.hpp"
#endif
#include <random>
using namespace std;


SubFrame::SubFrame(Point* ptsStart, Point* ptsStop, int nbPts) {
    this->ptsStart = ptsStart;
    this->ptsStop = ptsStop;
    this->nbPts = nbPts;
}

SubFrame::~SubFrame() {}

Point* SubFrame::getFirstPts() {
    return this->ptsStart;
}

Point* SubFrame::getStopPts() {
    return this->ptsStop;
}

bool SubFrame::isStellInSubFrame(Point* pts) {
    return pts != this->ptsStop;
}

vector<Point*> SubFrame::getNPlusProche(Point* pts, int nbPst) {
    if (this->nbPts <= FRAME_SIZE_MIN) return solveNPlusProche(pts,this,nbPst);
    vector<Point*> vec = this->toVector();
    return this->getNPlusProche(pts,vec,nbPst);
}

vector<Point*> solveNPlusProche(Point* pts, vector<Point*> candidats, int nbPts) {
    if (candidats.size() <= nbPts) return candidats;
    SubFrame sb(candidats[0],candidats.at(candidats.size()-1)->getSuivant(),candidats.size());
    return sb.getNPlusProche(pts,nbPts);
}

vector<Point*> solveNPlusProche(Point* pts, SubFrame* candidats, int nbPts) {
    vector<Point*> selectedPts;
    vector<double> dists;
    int IdxMax=0;
    double distMax=0;
    int i;
    Point* currentPts = candidats->getFirstPts();
    Point* stopPts = candidats->getStopPts();
    for (i=0; i<nbPts; i++) {
        if (currentPts == stopPts) continue;
        double dist = currentPts->getDistFrom(pts);
        selectedPts.push_back(currentPts);
        dists.push_back(dist);
        if (dist > distMax) {
            IdxMax = i;
            distMax = dist;
        }
        currentPts = currentPts->getSuivant();
    }
    while (currentPts != stopPts) {
        double dist = currentPts->getDistFrom(pts);
        if (dist < distMax) {
            selectedPts[IdxMax] = currentPts;
            dists[IdxMax] = dist;
            IdxMax = getIndexMaximum(dists);
            distMax = dists[IdxMax];
        }
        currentPts = currentPts->getSuivant();
    }
    return selectedPts;
}

int getIndexMaximum(vector<double> dist) {
    const int size = dist.size();
    double max = 0;
    int idx = 0;
    for (int i=0; i<size; i++) {
        if (max < dist[i]) {
            idx = i;
            max = dist[i];
        }
    }
    return idx;
}

vector<Point*> SubFrame::toVector() {
    vector<Point*> pts;
    Point* currentPts = this->getFirstPts();
    Point* stopPts = this->getStopPts();
    while (currentPts != stopPts) {
        pts.push_back(currentPts);
        currentPts = currentPts->getSuivant();
    }
    return pts;
}

vector<Point*> SubFrame::getNPlusProche(Point* pts, vector<Point*> candidats, int nbPts) {
    vector<Point*> selectedPts;
    Point* rPts = getRandomPts(candidats);
    int size = candidats.size();
    if (size <= FRAME_SIZE_MIN) return solveNPlusProche(pts,candidats,nbPts);
    for (int i=0; i<size;i++) {
        if (!candidats[i]->isAlignWith(pts,rPts)) continue;
        if (!candidats[i]->isClosserWhenAlign(pts,rPts)) continue;
        selectedPts.push_back(candidats[i]);
    }
    if (selectedPts.size() >= nbPts) return getNPlusProche(pts,selectedPts,nbPts);
    return getNPlusProche(pts,candidats,nbPts);
}

Point* getRandomPts(vector<Point*> vec) {
    return *getRandom(vec.begin(),vec.end());
}

template<typename Iter, typename RandomGenerator>
Iter getRandom(Iter start, Iter end, RandomGenerator& g) {
    uniform_int_distribution<> dis(0, distance(start,end)-1);
    advance(start,dis(g));
    return start;
}

template<typename Iter>
Iter getRandom(Iter start, Iter end) {
    static random_device rd;
    mt19937 gen(rd());
    return getRandom(start,end,gen);
}