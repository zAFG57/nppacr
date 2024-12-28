#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif

using namespace std;

vector<vector<int>> findcoordAround(vector<int> center, int nbAround);
void addForAllNCoord(vector<vector<int>> &points, vector<int> center, int nbAround, int nbCoord);
bool updateVectorIfUpdatable(vector<int> &coord, int nbAround);
void addAllVarriationOfCoord(vector<vector<int>> &points, vector<int> center, vector<int> coord, int nbAround);
bool getNextVarriation(vector<int> &coord, int idxStart, int nbAround);
void addIfInScop(vector<vector<int>> &points, vector<int> center, vector<int> coord);