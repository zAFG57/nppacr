#ifndef MAIN_H
#define MAIN_H
#include "main.hpp"
#endif
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
    vector<Point*> a = frame->getNPlusProche(pts,2);
    for (int i=0; i<a.size(); i++) {
        cout << a[i]->getVal()[0];
        cout << "\n";
    }
    return 0;
}