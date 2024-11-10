#ifndef MAIN_H
#define MAIN_H
#include "main.hpp"
#endif
#ifndef FRAME_H
#define FRAME_H
#include "frame.hpp"
#endif
#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
#ifndef DATA_READER_H
#define DATA_READER_H
#include "dataReader.hpp"
#endif
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


DataReader::DataReader(string file, int nbCoord, int nbValue) {
        this->fileUrl = file;
        this->nbCoord = nbCoord;
        this->nbValue = nbValue;
}

DataReader::~DataReader() {}

Frame* DataReader::readFile() {
    ifstream file(this->fileUrl);
    Frame* frame = new Frame();
    if (!file.is_open()) {
        cout << "problème avec le fichier csv \n";
        return nullptr;
    }
    while (file.peek() != EOF) {
        frame->ajouterPoint(this->getNextPoint(file));
    }
    file.close();
    return frame;
}

Point* DataReader::getNextPoint(ifstream& file) {
    vector<double> coord;
    vector<double> value;
    double temp;
    for (int i=0; i<this->nbCoord; i++) {
        file >> temp;
        coord.push_back(temp);
    }
    for (int i=0; i<this->nbValue; i++) {
        file >> temp;
        value.push_back(temp);
    }
    return new Point(value,coord);
}