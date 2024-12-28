#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
using namespace std;

Point::Point(vector<double> coord, vector<double> val) {
    this->coord = coord;
    this->val = val;
}

Point::Point(vector<double> coord) {
    this->coord = coord;
    vector<double> v = {};
    this->val = v;
}

Point::Point(vector<int> coord, vector<int> val) {
    vector<double> valeurDouble;
    vector<double> coordDouble;
    for (int i=0; i<val.size(); i++) {
        valeurDouble.push_back(static_cast<double>(val[i]));
        coordDouble.push_back(static_cast<double>(coord[i]));
    }
    this->coord = coordDouble;
    this->val = valeurDouble;
}

Point::~Point() {};


vector<double> Point::getCoord() {
    return this->coord;
}

vector<double> Point::getVal() {
    return this->val;
}

void Point::setVal(vector<double> val) {
    this->val = val;
}

double Point::getDistFrom(Point* pts) {
    vector<double> coord = pts->getCoord();
    int size = coord.size();
    double dist = 0;
    for (int i=0; i<size; i++) {
        double a = coord.at(i);
        double b = this->coord.at(i);
        dist += (a-b)*(a-b);
    }
    return dist;
}

bool Point::isCloser(Point* pts, double dist) {
    return pts->getDistFrom(this) <= dist;
}