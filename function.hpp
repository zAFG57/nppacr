#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif
#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif

using namespace std;

vector<vector<int>> findCoordAround(vector<int> &center, int nbAround);
void getNCoordDifferente(vector<int> &center, vector<vector<int>> &find, int nbDifferanteValue, int nbAround);
void getCompletVariationOfCoord(vector<int> &center, vector<vector<int>> &find, vector<int> &partialCoord);
void getPermutationOfCoord(vector<int> &center, vector<vector<int>> &find, vector<int> &coord);
void addPointToFindPoints(vector<int> &center, vector<vector<int>> &find, int* coord);

vector<Point*> getNPlusProche(vector<Point*> points, Point *pts, int nbVoisin);
int getIndexMaximum(vector<double> dist);