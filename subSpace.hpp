#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif
#ifndef POINT_H
#define POINT_H
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