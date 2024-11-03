#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
#ifndef SUBFRAME_H
#define SUBFRAME_h
#include "subframe.hpp"
#endif
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

bool SubFrame::isStellInSubFrame(Point* pts) {
    return pts != this->ptsStop;
}

vector<Point*> SubFrame::getNPlusProche(Point* pts, int nbPst) {
    return vector<Point*>{pts};
}