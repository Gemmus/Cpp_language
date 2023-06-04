#include <iostream>
#include <cmath>

using namespace std;

class Shape{
public:
	double area;
	double volume;
};

class Cube: public Shape{
public:
	double side;
Cube(double side){
	this->side = side;
	this->area = pow(side, 2) * 6;
	this->volume = pow(side, 3);
}
};

class Sphere: public Shape{
public:
	double radius;
Sphere(double radius){
	this->radius = radius;
	this->area = 4 * M_PI * pow(radius, 2);
	this->volume = 4 * M_PI * pow(radius, 3) / 3;
}
};

int main59(){

	Cube cube(10);
	cout << "The area of the cube is: " << cube.area << " and the volume is: " << cube.volume << endl;

	Sphere sphere(5);
	cout << "The area of the sphere is: " << sphere.area << " and the volume is: " << sphere.volume << endl;

	return 0;
}
