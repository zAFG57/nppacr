#include <vector>
#include "point.hpp"
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
};