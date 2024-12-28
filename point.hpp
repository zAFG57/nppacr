#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif

using namespace std;

class Point {
    private:
        vector<double> val;
        vector<double> coord;
    public:
        Point(vector<double> coord, vector<double> val);
        Point(vector<double> coord);
        Point(vector<int> coord, vector<int> val);
        ~Point();
        vector<double> getCoord();
        vector<double> getVal();
        void setVal(vector<double> val);
        double getDistFrom(Point* pts);
        bool isCloser(Point* pts, double dist);
};
