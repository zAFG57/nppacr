#ifndef VECTOR
#define VECTOR
#include <vector>
#endif
#ifndef FUNCTION
#define FUNCTION
#include "function.hpp"
#endif
#ifndef ALGO
#define ALGO
#include <algorithm>
#endif
using namespace std;

vector<vector<int>> findcoordAround(vector<int> center, int nbAround) {
    //renvoie tout les points autour du centre nbAround chouche autour
    int nbDim = center.size();
    vector<vector<int>> points = {};
    for (int i=0; i<nbDim; i++) {
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
    addAllVarriationOfCoord(points,center,coord);
    while (updateVectorIfUpdatable(coord,nbAround)) addAllVarriationOfCoord(points,center,coord);
}

void addAllVarriationOfCoord(vector<vector<int>> &point, vector<int> center, vector<int> coord) {
    // ajoute les points définit par the coord (but the coord is not always the in the right dimention)
}

void addIfInScop(vector<vector<int>> &points, vector<int> center, vector<int> coord) {
    // ajoute un un point si il n'est pas en dehors de l'espace (retour au subSapce fin du théorique)

}

bool updateVectorIfUpdatable(vector<int> &coord, int nbAround) {
    // modifie les veleur de coordonné jusqu'au max de nbAround puis renvoit false quand il ne peut plus
    
}