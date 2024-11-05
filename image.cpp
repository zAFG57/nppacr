#include <vector>
#include <iostream>
using namespace std;

#ifndef IMAGE_H
#define IMAGE_H
#include "image.hpp"
#endif
#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif

extern "C" {
    #define STB_IMAGE_IMPLEMENTATION
    #define STB_IMAGE_WRITE_STATIC
    #define STB_IMAGE_WRITE_IMPLEMENTATION
    #include "ext/stb_image.h"
    #include "ext/stb_image_write.h"
}

bool load_image(vector<unsigned char>& image, const string& filename, int& x, int&y) {
    int n;
    unsigned char* data = stbi_load(filename.c_str(), &x, &y, &n, 3);
    if (data != nullptr)
    {
        image = vector<unsigned char>(data, data + x * y * 3);
    }
    stbi_image_free(data);
    return (data != nullptr);
}

Image::Image(string file) {
    this->success = load_image(this->image, file, this->width, this->height);
}

Image::Image(vector<unsigned char> image, int whidth, int height) {
    this->image = image;
    this->width = width;
    this->height = height;
}


Image::~Image() {}

int Image::getWidth() {
    return this->width;
}

int Image::getHeight() {
    return this->height;
}

bool Image::isSuccess() {
    return this->success;
}

vector<int> Image::readPixel(int x, int y) {
    size_t index = this->nbV * (y * this->width + x);
    vector<int> ret = {this->image[index + 0], this->image[index + 1],this->image[index + 2]};
    return ret;
}

void Image::toVector(vector<vector<int>> &coords, vector<vector<int>> &vals) {
    for (int x=0; x<this->width; x++) {
        for (int y=0; y<this->height; y++) {
            vector<int> coord = {x,y};
            coords.push_back(coord);
            vals.push_back(this->readPixel(x,y));
        }
    }
}

vector<int> Image::readPixelIfNotwhite(int x, int y) {
    vector<int> col = this->readPixel(x,y);
    vector<int> vide;
    if (col[0] == 255 && col[1] == 255 && col[2] == 255) return vide;
    return col;
}

void Image::toVectorExeptWhite(vector<vector<int>> &coords, vector<vector<int>> &vals) {
    for (int x=0; x<this->width; x++) {
        for (int y=0; y<this->height; y++) {
            vector<int> color = this->readPixelIfNotwhite(x,y);
            if (color.size() == 3) {
                vector<int> coord = {x,y};
                coords.push_back(coord);
                vals.push_back(color);
            }
        }
    }
}

void Image::toVectorExeptWhite(vector<Point*> &allPts) {
    for (int x=0; x<this->width; x++) {
        for (int y=0; y<this->height; y++) {
            vector<int> color = this->readPixelIfNotwhite(x,y);
            if (color.size() == 3) {
                vector<int> coord = {x,y};
                Point* pts = new Point(color,coord);
                allPts.push_back(pts);
            }
        }
    }
}

void Image::toVector(vector<Point*> &allPts) {
    for (int x=0; x<this->width; x++) {
        for (int y=0; y<this->height; y++) {
            vector<int> coord = {x,y};
            vector<int> color = this->readPixel(x,y);
            Point* pts = new Point(color,coord);
            allPts.push_back(pts);
        }
    }
}

void Image::saveImage(const string& file) {
    unsigned char img6x5_rgb[this->width*this->height*this->nbV];
    for (int i=0; i<this->image.size();i++) {
        img6x5_rgb[i] = this->image[i] == 255 ? 0: this->image[i];
    }
    static int a = stbi_write_png(file.c_str(), this->width, this->height, this->nbV, img6x5_rgb, this->width*this->nbV);
}

void Image::writePixel(int x, int y, int n, unsigned char val) {
    size_t index = this->nbV * (y * this->width + x) + n;
    this->image[index] = val;
}

void Image::reLoadImage(vector<Point*> pts) {
    for (int i=0; i<pts.size(); i++) {
        Point* p = pts[i];
        vector<double> coord = p->getCoord();
        vector<double> color = p->getVal();
        this->writePixel(static_cast<int>(round(coord[0])),static_cast<int>(round(coord[1])),0,static_cast<unsigned char>(static_cast<int>(round(color[0]))));
        this->writePixel(static_cast<int>(round(coord[0])),static_cast<int>(round(coord[1])),1,static_cast<unsigned char>(static_cast<int>(round(color[1]))));
        this->writePixel(static_cast<int>(round(coord[0])),static_cast<int>(round(coord[1])),2,static_cast<unsigned char>(static_cast<int>(round(color[2]))));
    }
}