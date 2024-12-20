#ifndef VECTOR
#define VECTOR
#include <vector>
#endif
#ifndef POINT
#define POINT
#include "point.hpp"
#endif

using namespace std;

class SubSpace {
    private:
        vector<Point*> allPts;
        vector<double> centerCoord;
    public:
        SubSpace(vector<double> coordCenter);
        ~SubSpace();
        Point* getCenter();
        vector<Point*> getAllPts();
        int getNbPts();
        void addPts(Point* pts);
};