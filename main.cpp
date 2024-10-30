#include "main.hpp"
#include "point.hpp"
using namespace std;

int main() {
    vector<double> c1 = {0.5,12,-3};
    vector<double> c2 = {1,24,-6};
    vector<double> c3 = {2,48,-12};
    vector<double> c4 = {2,5,3};
    Point* p1 = new Point(6.5,c1);
    Point* p2 = new Point(13,c2);
    Point* p3 = new Point(13,c3);
    Point* p4 = new Point(13,c4);
    
    vector<double> a = p1->getCoord();
    vector<double> b = p2->getCoord();
    int size = a.size();
    for (int i=0; i<size; i++) {
        cout << a.at(i);
        cout << "\n";
        cout << b.at(i);
        cout << "\n";
    }
    if (p3->isAlignWith(p1,p2)) {
        cout << "p3 is align with p1->p2\n";
    }
    if (p4->isAlignWith(p1,p2)) {
        cout << "p3 is align with p1->p2\n";
    }
    if (p1->isClosserWhenAlign(p2,p3)) {
        cout << "p2 is closer to p1 than p3\n";
    }
    if (p2->isClosserWhenAlign(p3,p1)) {
        cout << "p3 is closer to p2 than p1\n";
    }
    if (p3->isClosserWhenAlign(p1,p2)) {
        cout << "p1 is closer to p3 than p2\n";
    }

    cout << p1->getDistFrom(p2);
    cout << "\n";
    cout << p1->getDistFrom(p3);
    return 0;
}