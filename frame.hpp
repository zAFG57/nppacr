#include <vector>
#include "point.hpp"


class Frame {
    private:
        vector<Point*> subFrame;
        Point* lastPts;
        int nbPts;
        int nbThread;
    public:
        Frame();
        ~Frame();
};