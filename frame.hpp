#include <vector>

#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
#ifndef SUBFRAME_H
#define SUBFRAME_H
#include "subFrame.hpp"
#endif
#ifndef MAIN_H
#define MAIN_H
#include "main.hpp"
#endif

class Frame {
    private:
        static const int minSizeSubFrame = FRAME_SIZE_MIN;
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
        vector<Point*> getNPlusProche(Point* pts, int nbPts);
};

vector<Point*> getPtsSubFrame(SubFrame* sub, Point* pts, int nbPts);