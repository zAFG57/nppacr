#ifndef MAIN_H
#define MAIN_H
#include "main.hpp"
#endif
#ifndef POINT_H
#define POINT_H
#include "point.hpp"
#endif
#ifndef FRAME_H
#define FRAME_H
#include "frame.hpp"
#endif
#ifndef SUBFRAME_H
#define SUBFRAME_h
#include "subframe.hpp"
#endif
#ifndef IMAGE_H
#define IMAGE_H
#include "image.hpp"
#endif
#ifndef INFERIMAGE_H
#define INFERIMAGE_H
#include "inferImage.hpp"
#endif
#ifndef DATA_READER_H
#define DATA_READER_H
#include "dataReader.hpp"
#endif
#ifndef DATA_EVALUATEUR_H
#define DATA_EVALUATEUR_H
#include "dataEvaluateur.hpp"
#endif
using namespace std;


int main() {
    string csvFile = "content/data.custom";
    int nbCoord = 7*2;
    int nbVal = 1;
    int nbVoisin = 4;
    DataEvaluateur* dataEvaluateur;
    dataEvaluateur = new DataEvaluateur(csvFile,nbCoord,nbVal);
    dataEvaluateur->doYourJob(nbVoisin);
}