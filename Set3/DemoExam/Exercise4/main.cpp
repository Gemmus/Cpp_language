/*
Class Point is defined as follows:
 
class Point {
 friend ostream& operator<<(ostream &o, const Point &p);
public:
 Point(float x0=0.0, float y0=0.0) {x = x0; y = y0;};
 void saveYourSelf(ostream &f) const {f << x << " " << y <<endl;};
 void readYourSelf(istream &f) {f >> x >> y;};
private:
 float x;
 float y;
};
 
Implementations of member functions are inside class definition to save space on the paper. As you
can see the member function saveYourSelf saves the contents of point objects on the disk file and
readYourSelf function can read the saved content of the object from the disk file.
 
Class Circle is defined as follows:
 
class Circle {
 friend ostream& operator<<(ostream &o, const Circle &c);
public:
 Circle(Point *cp0=NULL, float r0=0);
 void saveYourSelf(ostream &f) const;
 void readYourSelf(istream &f);
private:
 float radius;
 Point *cp;
};
 
Remark. Notice that class Circle contains a pointer to the center point. You may add an operation to
the class Circle if needed.
 
Implement all needed member functions and the friend function of the class Circle so
that the following program works correctly. The basic idea of the program is that it first creates a
circle c1 whose center point is (1.0, 2.0) and radius is 10.0. Then the information of this circle is
stored on the disk file. In the latter part of the program we want to create another circle c2 that is
similar to the first circle by reading the information from the disk file that was just created. There
should be no memory leaks in this test program.
 
int main() {
 //1. Saving
 Circle c1(new Point(1.0, 2.0), 10.0);
 ofstream f1("storage.txt"); //open the file object for writing
 c1.saveYourSelf(f1);
 f1.close();
 //2. Restoring
 Circle c2;
 ifstream f2("storage.txt"); //open the same file for reading
 c2.readYourSelf(f2);
METROPOLIA DEMO EXAM Page 4
Information Technology TX00EW59 C++ Programming 13.12.2023 JV
 cout << c2;
 f2.close();
 return 0;
}
*/

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
