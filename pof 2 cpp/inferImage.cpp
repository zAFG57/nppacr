#include "inferImage.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
#ifndef IMAGE_H
#define IMAGE_H
#include "image.hpp"
#endif
#ifndef FRAME_H
#define FRAME_H
#include "frame.hpp"
#endif

using namespace std;

InferImage::InferImage(Image* img, string savingImage) {
    this->img = img;
    this->img->toVectorExeptWhite(this->allPts);
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
        needInferation[coord[0]+coord[1]*width] = false;
    }
    for (int i=0; i<coords.size(); i++) {
        if (!needInferation[i]) continue;
        ret.push_back(coords[i]);
    }
    auto rd = random_device {}; 
    auto rng = default_random_engine { rd() };
    shuffle(begin(ret), end(ret), rng);
    return ret;
}

void InferImage::doYourJob() {
    vector<vector<double>> idx = this->genInferablePoint();
    Frame* f = new Frame(this->allPts);
    int size = idx.size();
    for (int i=0; i<size; i++) {
        vector<double> coord = idx[i];
        vector<double> color;
        Point* pts = new Point(color,coord);
        f->updatePts(pts, 3);
        f->ajouterPoint(pts);
        this->allPts.push_back(pts);
    }
    this->saveImage();
}