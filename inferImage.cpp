#include "inferImage.hpp"
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

InferImage::InferImage(Image* img, string savingImage) {
    this->img = img;
    this->savingImage = savingImage;
}

InferImage::~InferImage() {}

void InferImage::saveImage() {
    this->img->reLoadImage(this->allPts);
    this->img->saveImage(this->savingImage);
}

vector<vector<double>> InferImage::genInferablePoint() {
    int width = this->img->getWidth();
    int height = this->img->getHeight();
    int nb=width*height;
    int size = this->allPts.size();
    vector<bool> needInferation;
    vector<vector<double>> coords;
    vector<vector<double>> ret;
    for (int i=0; i<nb; i++) {
        needInferation.push_back(true);
        vector<double> coord = {static_cast<double>(i%width),static_cast<double>(i/width)};
        coords.push_back(coord);
    }
    for (int i=0; i<size; i++) {
        vector<double> coord = this->allPts[i]->getCoord();
        needInferation[coord[0]+coord[1]*height] = false;
    }
    for (int i=0; i<coords.size(); i++) {
        if (!needInferation[i]) continue;
        ret.push_back(coords[i]);
    }
    return ret;
}
