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
#ifndef IMAGE_H
#define IMAGE_H
#include "image.hpp"
#endif
using namespace std;


int main() {
    string imgFile = "content/original.png";
    string imgFile2 = "content/test.png";
    Image img(imgFile);
    if (!img.isSuccess()) {
        cout << "mauvais fichier 0_o \n";
    }
    vector<Point*> allPts;
    img.toVectorExeptWhite(allPts);
    cout << allPts.size() << "\n";
    img.reLoadImage(allPts);
    img.saveImage(imgFile2);
}