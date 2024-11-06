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
#ifndef INFERIMAGE_H
#define INFERIMAGE_H
#include "inferImage.hpp"
#endif
using namespace std;


int main() {
    string imgFile = "content/original.png";
    string imgFile2 = "content/test.png";
    Image* img = new Image(imgFile);
    InferImage infIm(img,imgFile2);
    infIm.doYourJob();
}