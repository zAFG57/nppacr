#include <iostream>
using namespace std;

class DataEvaluateur {
    private:
        string file;
        int nbCoord;
        int nbVal;
        Frame* frame;
        Point* firstPoint;
    public:
        DataEvaluateur(string file, int nbCoord, int nbVal);
        ~DataEvaluateur();
        void doYourJob(int nbVoisin);
};