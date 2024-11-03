#include <vector>
#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
using namespace std;

class SubFrame {
    private:
        Point* ptsStart;
        Point* ptsStop;
        int nbPts;
    public:
        SubFrame(Point* ptsStart, Point* ptsStop, int nbPts);
        ~SubFrame();
        Point* getFirstPts();
        bool isStellInSubFrame(Point* pts);
        vector<Point*> getNPlusProche(Point* pts, int nbPts);
};