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
using namespace std;

int main () {
    /*Space* space = new Space(2);
    vector<double> coord = {1,1};
    Point* pts = new Point(coord);
    space->AddPts(pts);*/

    vector<int> center = {5,5};
    vector<vector<int>> pts = findcoordAround(center,1);
    cout << pts.size() << " points trouve\n";
    for (int i=0; i<pts.size(); i++) {
        cout << "pts n " << i << "\n";
        for (int y=0; y<pts[i].size(); y++) cout << "\t" << pts[i][y];
        cout << "\n";
    }
    return 0;
}