#include "subFrame.hpp"
#include "point.hpp"
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