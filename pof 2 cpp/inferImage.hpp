#include <vector>
#include <iostream>

using namespace std;

class Image;
class Point;

class InferImage {
    private:
        string savingImage;
        Image* img;
        vector<Point*> allPts;
        vector<vector<double>> genInferablePoint();
    public:
        InferImage(Image* img, string savingImage);
        ~InferImage();
        void doYourJob();
        void saveImage();
};