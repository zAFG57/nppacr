#ifndef SUBSPACE
#define SUBSPACE
#include "subSpace.hpp"
#endif
#ifndef POINT
#define POINT
#include "point.hpp"
#endif
#ifndef VECTOR
#define VECTOR
#include <vector>
#endif
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

using namespace std;

SubSpace::SubSpace(vector<double> coordCenter) {
    this->centerCoord = vector<double>();
    for (int i=0; i<coordCenter.size(); i++) {
        this->centerCoord.push_back(coordCenter[i]);
    }
}

SubSpace::~SubSpace() {}

Point* SubSpace::getCenter() {
    return new Point(this->centerCoord);
}

vector<Point*> SubSpace::getAllPts() {
    return allPts;
}

int SubSpace::getNbPts() {
    return this->allPts.size();
}

void SubSpace::addPts(Point* pts) {
    this->allPts.push_back(pts);
}
