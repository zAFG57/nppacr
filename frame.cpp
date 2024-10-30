#include "frame.hpp"
#include "point.hpp"
#include "subFrame.hpp"
using namespace std;


Frame::Frame() {
    this->nbPts = 0;
    this->subFrame = {};
    this->nbThread = 1; // à changer par le vrai nombre de thread disponible
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
    //retourn le bon subFrame
}