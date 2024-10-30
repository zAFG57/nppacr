using namespace std;
#include <vector>

class Point {
    private:
        Point* suivant;
        double valeur;
        vector<double> coord;
    public:
        Point(double valeur, vector<double> coord);
        ~Point();
        void setSuivant(Point* suivant);
        vector<double> getCoord();
        double getVal();
        double getDistFrom(Point* pts);
        bool isAlignWith(Point* pts1, Point* pts2);
        bool isClosserWhenAlign(Point* ptsSource, Point* ptsCompare);
};
