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
// to save image =>
//https://github.com/nothings/stb/blob/master/tests/image_write_test.c

bool load_image(vector<unsigned char>& image, const string& filename, int& x, int&y) {
    int n;
    unsigned char* data = stbi_load(filename.c_str(), &x, &y, &n, 4);
    if (data != nullptr)
    {
        image = vector<unsigned char>(data, data + x * y * 4);
    }
    stbi_image_free(data);
    return (data != nullptr);
}

Image::Image(string file) {
    this->success = load_image(this->image, file, this->width, this->height);
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