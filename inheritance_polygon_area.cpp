//create a polygon class and derived different polygons (rectangle, triangle) from it
//write a function for area calculation for all the shapes

#include <iostream>

class Polygon {
public:
	Polygon(int a, int b): m_width(a), m_height(b) {}
	virtual int area() {
		return m_width*m_height;
	};

protected: //declared as protected so that so that child class can use them
	int m_width; //wdth of different shapes
	int m_height; //height of different shapes
};

class Rectangle : public Polygon {
public:
	Rectangle(int width, int height): Polygon(width, height) {}
	
	int area() override {
		return m_width*m_height;
	}
};

class Triangle : public Polygon {
public:
	Triangle(int width, int height) : Polygon(width, height) {}

	int area() override {
		return (m_width*m_height)/2;
	}
};

int main() {
	Rectangle* rec = new Rectangle(2, 4);
	std::cout << rec->area() << std::endl; //prints 8

	Triangle* tri = new Triangle(2, 4); //prints 4
	std::cout << tri->area();
	getchar();
}