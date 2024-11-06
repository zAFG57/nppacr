#include <vector>
#include <iostream>

#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
#ifndef IMAGE_H
#define IMAGE_H
#include "image.hpp"
#endif

using namespace std;

class InferImage {
    private:
        string savingImage;
        Image* img;
        vector<Point*> allPts;
        vector<vector<double>> genInferablePoint();
    public:
        InferImage(Image* img, string savingImage);
        ~InferImage();
        void doYourJob();
        void saveImage();
};