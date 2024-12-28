#ifndef SPACE_H
#define SPACE_H
#include "space.hpp"
#endif
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
#ifndef MAIN_H
#define MAIN_H
#include "main.hpp"
#endif
#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif
#ifndef MATH_H
#define MATH_H
#include <cmath>
#endif

using namespace std;

void Space::initializeSubSpace(int nbDimention) {
    vector<double> coord;
    for (int i=0; i<nbDimention; i++) {
        coord.push_back(0);
    }
    this->initializeRec(coord,0);
}

void Space::initializeRec(vector<double> &coord, int nb) {
    double step = 1.0/NB_SUB_DIVISION;
    double semiStep = step/2.0;
    double i=semiStep;
    while(i<1) {
        coord[nb] = i;
        if (nb+1 < coord.size()) {
            this->initializeRec(coord,nb+1);
        }
        if (nb+1 == coord.size()) this->addSubSpace(coord);
        i += step;
    }
}

void Space::addSubSpace(vector<double> &coord) {
    SubSpace* sb = new SubSpace(coord);
    this->allSubSpace.push_back(sb);
}

Space::Space(int nbDimention) {
    this->allSubSpace = {};
    this->initializeSubSpace(nbDimention);
    cout << "Space && SubSpace initialise \n";
    cout << "Nb SubSpace: " << this->allSubSpace.size() << "\n";
}

Space::~Space() {}

void Space::AddPts(Point* pts) {
    this->allSubSpace[this->findIndex(pts)]->addPts(pts);
}

int Space::findIndex(Point* pts) {
    vector<double> coord = pts->getCoord();
    int size = coord.size();
    int idxSubSpace = 0;
    double step = MAX_COORD_VALUE/NB_SUB_DIVISION;
    bool cond = true;
    for (int i=0; i<size; i++) {
        cond = cond && coord[i] == 1;
        idxSubSpace += floor(coord[i]/step) * pow(NB_SUB_DIVISION,size-i-1);
    }
    return cond ? this->allSubSpace.size()-1 : idxSubSpace;
}

vector<SubSpace> Space::getsubSpaceAroudPoint(Point* pts, int nbVoisin) {

}

void Space::getSubSpaceAroundSubSpace(vector<int> &subSpaceIdx, vector<int> &corner, int nbVoisin) {
    int nbPts = 0;
    if (subSpaceIdx.size() == 1) {
        nbPts = this->allSubSpace[subSpaceIdx[0]]->getNbPts();
        if (nbPts >= nbPts) return;
    }
    
}

void Space::updatePts(Point* pts, int nbVoisin) {
    vector<SubSpace> subSpaces = this->getsubSpaceAroudPoint(pts,nbVoisin);
    // get the point and then get the val then update point then return
}