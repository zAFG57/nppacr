#ifndef SUBSPACE_H
#define SUBSPACE_H
#include "subSpace.hpp"
#endif
#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif
#ifndef IOSTREAM_H
#define IOSTREAM_H
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

int SubSpace::getNumberOfPointAtDist(Point pts, double dist) {
    int nb = 0;
    for (int i=0; i<this->allPts.size(); i++) {
        if (dist >= pts.getDistFrom(this->allPts[i])) nb ++;
    }
    return nb;
}