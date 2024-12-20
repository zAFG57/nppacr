#ifndef VECTOR
#define VECTOR
#include <vector>
#endif
#ifndef POINT
#define POINT
#include "point.hpp"
#endif
#ifndef SUBSPACE
#define SUBSPACE
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
        void getSubSpaceAroundSubSpace(vector<int> &subSpaceIdx, vector<int> &corner);
    public:
        Space(int nbDimention);
        ~Space();
        void AddPts(Point* pts);
        void updatePts(Point* pts, int nbVoisin);
};