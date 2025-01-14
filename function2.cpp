#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif
#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif
#ifndef FUNCTION2_H
#define FUNCTION2_H
#include "function2.hpp"
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

vector<vector<int>> findCoordAround(vector<int> &center, int nbAround) {
    // trouve et renvoi toutes les coord à n distance autour du center
    int nbDimention = center.size();
    vector<vector<int>> find = {};
    for (int i=1; i<=nbDimention; i++) {
        getNCoordDifferente(center, find, i, nbAround);
    }
    return find;
}

void getNCoordDifferente(vector<int> &center, vector<vector<int>> &find, int nbDifferanteValue, int nbAround) {
    // trouve les différents partialCoord avec N nombre différents
    vector<int> coord = {};
    for (int i=0; i<nbDifferanteValue; i++) {
        coord.push_back(-nbAround+i);
    }
    getCompletVariationOfCoord(center,find,coord);
    bool modified;
    int cursor;
    int val;
    while (true)
    {
        modified = false;
        cursor = coord.size();
        while(!modified) {
            if (cursor < 0) return;
            if (coord[cursor] + coord.size() -1 - cursor < nbAround) {
                modified = true;
                coord[cursor] ++;
                val = coord[cursor] +1;
                cursor ++;
                while (cursor<coord.size()) {
                    coord[cursor] = val;
                    cursor++;
                    val++;
                }
            } else {
                cursor --;
            }
        }
        getCompletVariationOfCoord(center,find,coord);
    }
}

void getCompletVariationOfCoord(vector<int> &center, vector<vector<int>> &find, vector<int> &partialCoord) {
    // trouve les coords complet à partir des partials coord
    vector<int> coord = {};
    for (int i=0; i<partialCoord.size(); i++) {
        coord.push_back(partialCoord[i]);
    }
    while(coord.size() != center.size()) {
        coord.push_back(partialCoord[0]);
    }
    getPermutationOfCoord(center,find,coord);
    // TODO: 
    // ici faire la boucle de modification avec les deux cursors et générer les permutations.
}

void getPermutationOfCoord(vector<int> &center, vector<vector<int>> &find, vector<int> &coord) {
    // trouve les apermutations possible d'un coord
    int intCoord[center.size()];
    for (int i=0; i<center.size(); i++) {
        intCoord[i] = coord[i];
    }
    while(next_permutation(intCoord,intCoord+center.size()-1)) {
        addPointToFindPoints(center,find,intCoord);
    }
}

void addPointToFindPoints(vector<int> &center, vector<vector<int>> &find, int* coord) {
    // ajoute le coord dans les find si coord dans l'espace.
    vector<int> finalCoord = {};
    for (int i=0; i<center.size(); i++) {
        finalCoord.push_back(coord[i] + center[i]);
        if (finalCoord[i] > MAX_COORD_VALUE || finalCoord[i] < MIN_COORD_VALUE) return;
    }
    find.push_back(finalCoord);
}