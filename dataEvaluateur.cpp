#ifndef DATA_READER_H
#define DATA_READER_H
#include "dataReader.hpp"
#endif
#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
#ifndef FRAME_H
#define FRAME_H
#include "frame.hpp"
#endif
#ifndef DATA_EVALUATEUR_H
#define DATA_EVALUATEUR_H
#include "dataEvaluateur.hpp"
#endif

#include <math.h>

DataEvaluateur::DataEvaluateur(string file, int nbCoord, int nbVal) {
    this->file = file;
    this->nbCoord = nbCoord;
    this->nbVal = nbVal;
    DataReader dataReader(this->file,this->nbCoord,this->nbVal);
    this->frame = dataReader.readFile();
    this->firstPoint = this->frame->getFirstPts();
    cout << "DataEvaluateur initialise\n";
}

DataEvaluateur::~DataEvaluateur() {}

void DataEvaluateur::doYourJob(int nbVoisin) {
    Point* pts = this->firstPoint;
    vector<double> avgSum;
    int nb = 0;
    // initialisation
    for (int i=0; i<this->nbVal; i++) {
        avgSum.push_back(0);
    }
    // calcul diff
    while (pts != nullptr) {
        nb ++;
        if (nb%50==0) cout << nb << "\n";
        vector<double> ancien = pts->getVal();
        frame->updatePts(pts,nbVoisin);
        vector<double> nouveau = pts->getVal();
        for (int i=0; i<this->nbVal; i++) {
            avgSum[i] += fabs(ancien[i]-nouveau[i]);
        }
        pts = pts->getSuivant();
    }
    cout << "val calue\n";
    // calcul avg;
    for (int i=0; i<this->nbVal; i++) {
        avgSum[i] = avgSum[i]/nb;
    }
    // affichage:
    cout << "erreur moyenne calcule sur " << nb << " point: \n";
    for (int i=0; i<this->nbVal; i++) {
        cout << "\tvaleur " << i << ":\t" << avgSum[i] << "\n";
    }
}