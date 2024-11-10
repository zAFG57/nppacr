#include <fstream>
#ifndef MAIN_H
#define MAIN_H
#include "main.hpp"
#endif
class Frame;
class Point;

class DataReader {
    private:
        Point* getNextPoint(ifstream& file);
        string fileUrl;
        int nbCoord;
        int nbValue;
    public:
        DataReader(string file,int nbCoord, int nbValue);
        ~DataReader();
        Frame* readFile();
};