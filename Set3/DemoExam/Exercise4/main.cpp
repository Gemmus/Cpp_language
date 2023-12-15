#include <iostream>
#include <fstream>

using namespace std;

class Point {
    friend ostream& operator<<(ostream &o, const Point &p);
public:
    Point(float x0=0.0, float y0=0.0) {x = x0; y = y0;}
    void saveYourSelf(ostream &f) const {f << x << " " << y << endl;};
    void readYourSelf(istream &f) {f >> x >> y;};
private:
    float x;
    float y;
};

class Circle {
    friend ostream& operator<<(ostream &o, const Circle &c);
public:
    Circle(Point *cp0=NULL, float r0=0);
    void saveYourSelf(ostream &f) const {
        cp->Point::saveYourSelf(f);
        f << radius;
    }
    void readYourSelf(istream &f) {
        cp->readYourSelf(f);
        f >> radius;
    }
private:
    float radius;
    Point *cp;
};


int main() {
    //1. Saving
    Circle c1(new Point(1.0, 2.0), 10.0);
    ofstream f1("storage.txt"); //open the file object for writing
    c1.saveYourSelf(f1);
    f1.close();
    //2. Restoring
    Circle c2;
    ifstream f2("storage.txt"); //open the same file for reading
    c2.readYourSelf(f2);}
