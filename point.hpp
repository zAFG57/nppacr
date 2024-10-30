using namespace std;
#include <vector>

class Point {
    private:
        Point* suivant;
        vector<double> valeur;
        vector<double> coord;
    public:
        Point(vector<double> valeur, vector<double> coord);
        ~Point();
        void setSuivant(Point* suivant);
        Point* getSuivant();
        vector<double> getCoord();
        vector<double> getVal();
        double getDistFrom(Point* pts);
        bool isAlignWith(Point* pts1, Point* pts2);
        bool isClosserWhenAlign(Point* ptsSource, Point* ptsCompare);
};
