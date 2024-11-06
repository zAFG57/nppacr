#include <vector>

#ifndef MAIN_H
#define MAIN_H
#include "main.hpp"
#endif

class SubFrame;
class Point;

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
        Frame(vector<Point*> allPts);
        ~Frame();
        void ajouterPoint(Point* point);
        SubFrame* getsubframe(int index);
        vector<Point*> getNPlusProche(Point* pts, int nbPts);
        void updatePts(Point* pts, int nbPts);
};

vector<Point*> getPtsSubFrame(SubFrame* sub, Point* pts, int nbPts);