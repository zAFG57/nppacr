#include "main.hpp"
#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
#ifndef FRAME_H
#define FRAME_H
#include "frame.hpp"
#endif
#ifndef SUBFRAME_H
#define SUBFRAME_h
#include "subframe.hpp"
#endif
using namespace std;

int main() {
    Point* pts = new Point(vector<double>{57.5}, vector<double>{});
    Frame* frame = new Frame();
    frame->ajouterPoint(pts);
    frame->getNPlusProche(pts,2);
    return 0;
}