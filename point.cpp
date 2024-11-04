#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
#include <vector>
using namespace std;

Point::Point(vector<double> valeur, vector<double> coord) {
    this->coord = coord;
    this->valeur = valeur;
}

Point::Point(vector<int> valeur, vector<int> coord) {
    vector<double> valeurDouble;
    vector<double> coordDouble;
    for (int i=0; i<valeur.size(); i++) {
        valeurDouble.push_back(static_cast<double>(valeur[i]));
        coordDouble.push_back(static_cast<double>(coord[i]));
    }
    this->coord = coordDouble;
    this->valeur = valeurDouble;
}

Point::~Point() {};

void Point::setSuivant(Point* suivant) {
    this->suivant = suivant;
}

Point* Point::getSuivant() {
    return this->suivant;
}

vector<double> Point::getCoord() {
    return this->coord;
}

vector<double> Point::getVal() {
    return this->valeur;
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

bool Point::isAlignWith(Point* pts1, Point* pts2) {
    vector<double> coord1 = pts1->getCoord();
    vector<double> coord2 = pts2->getCoord();
    int size = coord1.size();
    for (int i=0; i<size; i++) {
        double c1 = coord1.at(i);
        double c2 = coord2.at(i);
        double c3 = this->coord.at(i);
        double s1 = c1-c2;
        double s2 = c1-c3;
        if ((s1>=0 && s2<=0) || (s1<=0 && s2>=0)) return false;
    }
    return true;
}

bool Point::isClosserWhenAlign(Point* ptsSource, Point* ptsCompare) {
    vector<double> coordSource = ptsSource->getCoord();
    vector<double> coordCompare = ptsCompare->getCoord();
    int size = coordSource.size();
    for (int i=0; i<size; i++) {
        double c1 = coordSource.at(i);
        double c2 = coordCompare.at(i);
        double c3 = this->coord.at(i);
        double s1 = c1-c2;
        double s2 = c1-c3;
        if ((s1>=0 && s2>=s1) || (s1<=0 && s2<=s1)) return false;
    }
    return true;
}