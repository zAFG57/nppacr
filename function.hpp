#ifndef VECTOR
#define VECTOR
#include <vector>
#endif

using namespace std;

vector<vector<int>> findcoordAround(vector<int> center, int nbAround);
void addForAllNCoord(vector<vector<int>> &points, vector<int> center, int nbAround, int nbCoord);
bool updateVectorIfUpdatable(vector<int> &coord, int nbAround);
void addAllVarriationOfCoord(vector<vector<int>> &points, vector<int> center, vector<int> coord);
void addIfInScop(vector<vector<int>> &points, vector<int> center, vector<int> coord);