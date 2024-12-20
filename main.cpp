#ifndef MAIN
#define MAIN
#include "main.hpp"
#endif
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef SPACE
#define SPACE
#include "space.hpp"
#endif
#ifndef MATH
#define MATH
#include <cmath>
#endif
using namespace std;

int main () {
    Space* space = new Space(2);
    vector<double> coord = {1,1};
    Point* pts = new Point(coord);
    space->AddPts(pts);
    return 0;
}