#include<iostream>
#include "MyVector.h"
int main()
{
	MyVector v;
	std::cout << v << std::endl;
	v.pushBack(99);
	std::cout << v << std::endl;
	v.pushBack(199);
	std::cout << v << std::endl;

	MyVector v1(11, 5);
	std::cout << v1 << std::endl;
	v1.pushBack(99);
	std::cout << v1 << std::endl;
	v1.pushBack(199);
	std::cout << v1 << std::endl;

	MyVector v2(v1);
	std::cout << v2 << std::endl;

	//initilization of MyVector instance through initializer_list data structure
	MyVector v3{ 1, 2, 3, 4, 5 }; //this is how we inilize STL vector using initilizer_list
	std::cout << v3 << std::endl; //implemented the same here for MyVector class
	getchar();
	return 0;
}
