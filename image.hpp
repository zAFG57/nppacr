#include <vector>

class Point;

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
        Image(vector<unsigned char> image, int whidth, int height);
        ~Image();
        int getWidth();
        int getHeight();
        bool isSuccess();
        vector<int> readPixel(int x, int y);
        void writePixel(int x, int y, int n, unsigned char val);
        void toVector(vector<vector<int>> &coords, vector<vector<int>> &vals);
        void toVector(vector<Point*> &allPts);
        vector<int> readPixelIfNotwhite(int x, int y);
        void toVectorExeptWhite(vector<vector<int>> &coords, vector<vector<int>> &vals);
        void toVectorExeptWhite(vector<Point*> &allPts);
        void saveImage(const string& file);
        void reLoadImage(vector<Point*> pts);
};