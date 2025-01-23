#ifndef MAIN_H
#define MAIN_H
#include "main.hpp"
#endif
#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif
#ifndef SPACE_H
#define SPACE_H
#include "space.hpp"
#endif
#ifndef MATH_H
#define MATH_H
#include <cmath>
#endif
#ifndef FUNCTION_H
#define FUNCTION_H
#include "function.hpp"
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
#ifndef INFER_IMAGE_H
#define INFER_IMAGE_H
#include "inferImage.hpp"
#endif
using namespace std;

int main () {
    Image* img = new Image("content/original.png");
    InferImage* infer = new InferImage(img,"content/newAlgo.png");
    cout << "before" << endl;
    infer->doYourJob();
    cout << "Saving image" << endl;
    infer->saveImage();
    return 0;
}