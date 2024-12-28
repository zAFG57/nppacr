#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif
#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
#ifndef SUBSPACE_H
#define SUBSPACE_H
#include "subSpace.hpp"
#endif
using namespace std;

class Space {
    private:
        vector<SubSpace*> allSubSpace;
        void initializeSubSpace(int nbDimention);
        void initializeRec(vector<double> &coord, int nb);
        void addSubSpace(vector<double> &coord);
        int findIndex(Point* pts);

        vector<SubSpace> getsubSpaceAroudPoint(Point* pts,int nbVoisin);
        void getSubSpaceAroundSubSpace(vector<int> &subSpaceIdx, vector<int> &corner, int nbVoisin);
    public:
        Space(int nbDimention);
        ~Space();
        void AddPts(Point* pts);
        void updatePts(Point* pts, int nbVoisin);
};