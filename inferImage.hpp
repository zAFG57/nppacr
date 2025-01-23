#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif
#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif
#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
#ifndef IMAGE_H
#define IMAGE_H
#include "image.hpp"
#endif
#ifndef SPACE_H
#define SPACE_H
#include "space.hpp"
#endif
using namespace std;


class InferImage {
    private:
        string savingImage;
        Image* img;
        Space* space;
        vector<Point*> allPts;
        vector<vector<double>> genInferablePoint();
        void addAllKnownPixel();
    public:
        InferImage(Image* img, string savingImage);
        ~InferImage();
        void doYourJob();
        void saveImage();
};