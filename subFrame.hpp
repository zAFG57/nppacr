#include <vector>

using namespace std;

class Point;

class SubFrame {
    private:
        Point* ptsStart;
        Point* ptsStop;
        int nbPts;
    public:
        SubFrame(Point* ptsStart, Point* ptsStop, int nbPts);
        ~SubFrame();
        Point* getFirstPts();
        Point* getStopPts();
        bool isStellInSubFrame(Point* pts);
        vector<Point*> getNPlusProche(Point* pts, int nbPts);
        vector<Point*> getNPlusProche(Point* pts, vector<Point*> candidats, int nbPts);
        vector<Point*> toVector();
};

vector<Point*> solveNPlusProche(Point* pts, vector<Point*> candidats, int nbPts);
vector<Point*> solveNPlusProche(Point* pts, SubFrame* candidats, int nbPts);
int getIndexMaximum(vector<double> dist);
Point* getRandomPts(vector<Point*> vec);
template<typename Iter, typename RandomGenerator>
Iter getRandom(Iter start, Iter end, RandomGenerator& g);
template<typename Iter>
Iter getRandom(Iter start, Iter end);
