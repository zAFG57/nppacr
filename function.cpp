#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif
#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif
#ifndef FUNCTION_H
#define FUNCTION_H
#include "function.hpp"
#endif
#ifndef ALGO_H
#define ALGO_H
#include <algorithm>
#endif
#ifndef MAIN_H
#define MAIN_H
#include "main.hpp"
#endif
using namespace std;

vector<vector<int>> findcoordAround(vector<int> center, int nbAround) {
    //renvoie tout les points autour du centre nbAround couche autour
    int nbDim = center.size();
    vector<vector<int>> points = {};
    for (int i=1; i<=nbDim; i++) {
        cout << "dim " << i << "\n";
        addForAllNCoord(points,center,nbAround,i);
    }
    return points;
}

void addForAllNCoord(vector<vector<int>> &points, vector<int> center, int nbAround, int nbCoord) {
    // ajoute les points définit par n valeurs différentes de coordoné
    vector<int> coord = {};
    int c = -nbAround;
    for (int i=0; i<nbCoord; i++) {
        coord.push_back(c);
        c++;
    }
    addAllVarriationOfCoord(points,center,coord, nbAround);
    cout << "coord " << nbCoord << "\n";
    while (updateVectorIfUpdatable(coord,nbAround)) addAllVarriationOfCoord(points,center,coord, nbAround);
}

void addAllVarriationOfCoord(vector<vector<int>> &points, vector<int> center, vector<int> coord, int nbAround) {
    // ajoute les points définit par the coord (but the coord is not always the in the right dimention)
    // abc -> abcaa abcab abcac abcbb abcbc abccc
    int size = coord.size();
    int intCoord[center.size()];
    vector<int> copyIntCoord = {};
    for (int i=0; i<size; i++) {
        intCoord[i] = coord[i];
        copyIntCoord.push_back(coord[i]);
    }
    for (int i=size; i<center.size(); i++) {
        intCoord[i] = coord[0];
        coord.push_back(coord[0]);
        copyIntCoord.push_back(coord[0]);
    }
    sort(intCoord,intCoord+center.size());
    addIfInScop(points,center,copyIntCoord);
    while(next_permutation(intCoord,intCoord+center.size()-1)) {
        sort(intCoord,intCoord+center.size());
        for (int i=0; i<center.size(); i++) copyIntCoord[i] = intCoord[i];
        addIfInScop(points,center,copyIntCoord);
    }
    while (getNextVarriation(coord,size,nbAround)) {
        for (int i=0; i<center.size(); i++) {
            intCoord[i] = coord[i];
            copyIntCoord[i] = intCoord[i];
        }
        sort(intCoord,intCoord+center.size());
        addIfInScop(points,center,copyIntCoord);
        while(next_permutation(intCoord,intCoord+center.size())) {
            for (int i=0; i<center.size(); i++) copyIntCoord[i] = intCoord[i];
            addIfInScop(points,center,copyIntCoord);
        }
    }
}

bool getNextVarriation(vector<int> &coord, int idxStart, int nbAround) {
    // modifie et renvoie true les coord pour avoir la varriation d'appès.
    // abc -> abcaaa abcaab abcaac abcabb abcabc abcacc abcbbb abcbbc abcbbc abcbcc abcccc
    if (coord.size() == idxStart) return false;
    int idx = coord.size()-1;
    while (coord[idx] == coord[idxStart-1]) {
        if (idx == idxStart) return false;
        idx --;
    }
    coord[idx] ++;
    int res = coord[idx];
    idx++;
    while (idx!=coord.size()) {
        coord[idx] = res;
        idx++;
    }
    return true;
}

void addIfInScop(vector<vector<int>> &points, vector<int> center, vector<int> coord) {
    // ajoute un un point si il n'est pas en dehors de l'espace (retour au subSapce fin du théorique)
    vector<int> pts = {};
    for (int i=0;i<coord.size(); i++) {
        int c = coord[i]+center[i];
        if (c<0 || c>MAX_COORD_VALUE) return;
        pts.push_back(c);
    }
    points.push_back(pts);
}

bool updateVectorIfUpdatable(vector<int> &coord, int nbAround) {
    // modifie les veleur de coordonné jusqu'au max de nbAround puis renvoit false quand il ne peut plus
    // abc abd acd bcd
    // ab ac ad bc bd cd
    int idx = coord.size()-1;
    while (coord[idx] == nbAround) {
        if (idx == 0) return false;
        idx --;
    }
    while (coord[idx] + idx - coord.size() > nbAround) {
        if (idx == 0) return false;
        idx --;
    }
    coord[idx] ++;
    int res = coord[idx];
    idx++;
    res ++;
    while (idx!=coord.size()) {
        coord[idx] = res;
        idx++;
        res++;
    }
    return true;
}