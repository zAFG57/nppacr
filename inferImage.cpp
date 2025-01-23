#ifndef INFER_IMAGE_H
#define INFER_IMAGE_H
#include "inferImage.hpp"
#endif
#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif
#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif
#ifndef ALGO_H
#define ALGO_H
#include <algorithm>
#endif
#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
#ifndef IMAGE_H
#define IMAGE_H
#include "image.hpp"
#endif

#include <random>

using namespace std;

InferImage::InferImage(Image* img, string savingImage) {
    this->img = img;
    this->img->toVectorExeptWhite(this->allPts);
    this->savingImage = savingImage;
    this->space = new Space(2);
}

InferImage::~InferImage() {}

void InferImage::saveImage() {
    this->img->reLoadImage(this->allPts);
    this->space->~Space();
    this->space = nullptr;
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
    random_device rd; 
    default_random_engine rng { rd() };
    shuffle(begin(ret), end(ret), rng);
    return ret;
}

void InferImage::addAllKnownPixel() {
    for (int i=0; i<this->allPts.size(); i++) {
        cout << i << endl;
        this->space->AddPts(this->allPts[i]);
    }
}

void InferImage::doYourJob() {
    vector<vector<double>> idx = this->genInferablePoint();
    cout << "idx size: " << idx.size() << endl;
    this->addAllKnownPixel();
    cout << "hello" << endl;
    int size = idx.size();
    for (int i=0; i<size; i++) {
        vector<double> coord = idx[i];
        Point* pts = new Point(coord);
        this->space->updatePts(pts,8);
        this->allPts.push_back(pts);
    }
    this->saveImage();
}