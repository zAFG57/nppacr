#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
#include <vector>
bool load_image(vector<unsigned char>& image, const string& filname, int& x, int& y);

class Image {
    private:
        vector<unsigned char> image;
        static const size_t nbV = 3;
        int width;
        int height;
        bool success;
    public:
        Image(string file);
        ~Image();
        int getWidth();
        int getHeight();
        bool isSuccess();
        vector<int> readPixel(int x, int y);
        void toVector(vector<vector<int>> &coords, vector<vector<int>> &vals);
        vector<int> readPixelIfNotwhite(int x, int y);
        void toVectorExeptWhite(vector<vector<int>> &coords, vector<vector<int>> &vals);
        void toVectorExeptWhite(vector<Point*> &allPts);
};