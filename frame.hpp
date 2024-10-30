#include <vector>
#include "point.hpp"
#include "subFrame.hpp"


class Frame {
    private:
        static const int minSizeSubFrame = 50;
        vector<Point*> subFrame;
        Point* lastPts;
        int nbPts;
        int nbThread;
        int nbPtsNotUpdate;
        void updateSubFrame();
    public:
        Frame();
        ~Frame();
        void ajouterPoint(Point* point);
        SubFrame* getsubframe(int index);
};