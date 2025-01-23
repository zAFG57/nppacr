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
#ifndef FUNCTION_H
#define FUNCTION_H
#include "function.hpp"
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
        cout << coord[i] << endl;
        cond = cond && coord[i] == 1;
        idxSubSpace += floor(coord[i]/step) * pow(NB_SUB_DIVISION,size-i-1);
    }
    cout << cond ? this->allSubSpace.size()-1 : idxSubSpace ;
    cout << endl;
    return cond ? this->allSubSpace.size()-1 : idxSubSpace;
}

SubSpace Space::getSubspaceFromCoord(vector<int> coord) {
    int idx = 0;
    int puissance = 1;
    for (int i=0; i<coord.size(); i++) {
        idx += coord[i] * puissance;
        puissance = puissance * NB_SUB_DIVISION;
    }
    return *this->allSubSpace[idx];
}

vector<SubSpace> Space::getsubSpaceAroudPoint(Point* pts, int nbVoisin) {
    vector<int> center = {};
    double step = MAX_COORD_VALUE/NB_SUB_DIVISION;
    vector<double> coord = pts->getCoord();
    for (int i=0;i<coord.size();i++) {
        center.push_back(coord[i]/step);
    }

    int nbAround = 0;
    int nbFound = 0;
    vector<vector<int>> subSpaceIntCoord;
    vector<SubSpace> subspaces;
    while (nbFound < nbVoisin) {
        nbAround ++;
        nbFound = 0;
        subSpaceIntCoord = findCoordAround(center, nbAround);
        subspaces = {};
        for (int i=0; i<subSpaceIntCoord.size(); i++) {
            subspaces.push_back(this->getSubspaceFromCoord(subSpaceIntCoord[i]));
            nbFound += subspaces[i].getNumberOfPointAtDist(*pts,step);
        }
    }
    return subspaces;
}


void Space::getSubSpaceAroundSubSpace(vector<int> &subSpaceIdx, vector<int> &corner, int nbVoisin) {
    int nbPts = 0;
    if (subSpaceIdx.size() == 1) {
        nbPts = this->allSubSpace[subSpaceIdx[0]]->getNbPts();
        if (nbPts >= nbPts) return;
    }
}

vector<double> Space::getValFromPoint(Point* pts, int nbVoisin) {
    vector<SubSpace> subSpaces = this->getsubSpaceAroudPoint(pts,nbVoisin);
    vector<Point*> points = {};
    for (int i=0; i<subSpaces.size(); i++) {
        vector<Point*> pts = subSpaces[i].getAllPts();
        for (int y=0; y<pts.size(); y++) {
            points.push_back(pts[y]);
        }
    }
    vector<Point*> selectedPts = getNPlusProche(points,pts,nbVoisin);
    vector<double> val = selectedPts[0]->getVal();
    for (int i=1; i<selectedPts.size(); i++) {
        vector<double> valTmp = selectedPts[i]->getVal();
        for (int y=0; y<val.size(); y++) {
            val[y] += valTmp[y];
        }
    }
    for (int i=0; i<val.size(); i++) {
        val[i] = val[i]/nbVoisin;
    }
    return val;
}

void Space::updatePts(Point* pts, int nbVoisin) {
    pts->setVal(this->getValFromPoint(pts,nbVoisin));
    this->allSubSpace[this->findIndex(pts)]->addPts(pts);
}