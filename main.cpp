#ifndef MAIN_H
#define MAIN_H
#include "main.hpp"
#endif
#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
#ifndef FRAME_H
#define FRAME_H
#include "frame.hpp"
#endif
#ifndef SUBFRAME_H
#define SUBFRAME_h
#include "subframe.hpp"
#endif
#ifndef IMAGE_H
#define IMAGE_H
#include "image.hpp"
#endif
#ifndef INFERIMAGE_H
#define INFERIMAGE_H
#include "inferImage.hpp"
#endif
#ifndef DATA_READER_H
#define DATA_READER_H
#include "dataReader.hpp"
#endif
using namespace std;


int main() {
    string csvFile = "content/data.custom";
    DataReader dataReader(csvFile,7*2,1);
    Frame* frame = dataReader.readFile();
    vector<double> val = {};
    vector<double> coord = {0.17338709677419356, 0.0, 0.30403225806451467, 0.07499999999999964, 0.5991935483870964, 0.2266129032258057, 0.9024193548387086, 0.4064516129032247, 0.9782258064516125, 0.42499999999999855, 0.8774193548387094, 0.6395161290322577, 1.0, 0.6032258064516125};
    Point* pts = new Point(val,coord);
    frame->updatePts(pts,10);
    vector<double> bon = pts->getVal();
    cout << bon[0];
}