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
#include "function2.hpp"
#endif
#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif
#ifndef ALGO_H
#define ALGO_H
#include <algorithm>
#endif
using namespace std;

int main () {
    /*Space* space = new Space(2);
    vector<double> coord = {1,1};
    Point* pts = new Point(coord);
    space->AddPts(pts);*/

    vector<int> center = {5,5,5,5,5,5,5,5};
    vector<vector<int>> pts = findCoordAround(center,2);
    cout << pts.size() << " points trouve\n";
    vector<int> f = {};
    int variant;
    int puissance;
    for (int i=0; i<pts.size(); i++) {
        variant = 0;
        puissance = 1;
        for (int y=pts[i].size()-1; y>=0; y--) {
            variant += pts[i][y] * puissance;
            puissance = puissance * 10;
        }
        f.push_back(variant);
    }
    
    sort(f.begin(),f.end());

    for (int i=0; i<f.size(); i++) {
        //cout << f[i] << "\n";
    }
    return 0;
}