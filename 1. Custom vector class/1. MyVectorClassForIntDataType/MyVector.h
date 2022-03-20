#pragma once

#include<ostream> //for the print functionlity of MyVector implementation testing

class MyVector
{
public:
	MyVector(); //constructor for default initialization
	~MyVector(); //destructor to destroy the M/M, since once we create any instance if this class due to presence of pointer M/M on heap will be allocated
	
	//copy constructor
	MyVector(const MyVector& rhs);
	MyVector(int numberOfElements, int value); //constructor with element and all are initialized to a value

	//initilize vector using initializer list
	MyVector(const std::initializer_list<int>& list);

	//member functions implementation
	void pushBack(int value); // pushes value to the vector

	//getter functions. set them to const type
	bool empty() const;
	int size() const;
	int capacity() const;

	//test equality of two vectors, this should also be const because we are not changing anything while testing the equality
	//if you are putting const in the argument, you cannot call a method which is non const on rhs. e.g, rhs.pushBack is illegal in the definition of equality checking operartor!
	bool operator==(const MyVector& rhs) const;
	//not equal operator overloading
	bool operator!=(const MyVector& rhs) const;

	//Friend function can access private members of a class directly
	friend std::ostream& operator<<(std::ostream& ostr, const MyVector& rhs);
private:
	//remember to use diffenrt name of member variables and memeber functions, else compiler gets confused, e.g., here I have used lowe case and upper case to distinguish them
	int Capacity; //capacity of the vector
	int Size; //current size of the vector
	int * Array; //int pointer for the vector

};
