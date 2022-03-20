#include "MyVector.h"
MyVector::MyVector()
	:Size(0), //size 0 >>empty vector
	Capacity(5), //capacity 5 >>max allwed elemnt should be 5
	Array(new int[Capacity])
{
	//All initialized! Nothing here... We would need more memebr variables but for now all the memeber variables we have initialized
}

MyVector::~MyVector()
{
	delete[] Array;  //deletes the pointer to the M/M
}

MyVector::MyVector(const MyVector & rhs)
	:Size(rhs.Size),
	Capacity(rhs.Capacity),
	Array(new int[Capacity])
{
	for (int i = 0; i < rhs.size(); ++i)
	{
		Array[i] = rhs.Array[i]; //elementwise copy, here we have one block of M/M where two seperate pointers are pointing, if anyone changes the value it can affect the other
	}
}

//so it would be better if we do a deep copy here, copy all the value to a diiferent chunk of M/M and point to that
MyVector::MyVector(int numberOfElements, int value)
	:Size(numberOfElements),
	Capacity(numberOfElements + 5), //extra 5 spaces for capacity
	Array(new int[Capacity])
{
	for (int i = 0; i < Size; ++i)
	{
		Array[i] = value;
	}
}

MyVector::MyVector(const std::initializer_list<int>& list)
	:Size(0),
	Capacity(list.size()+5), //capacity is whatever inside the list plus 5, here, size is a method implemented in list which return length of list
	Array(new int[Capacity])
{
	for (int i : list)
	{
		pushBack(i);
	}
}

void MyVector::pushBack(int value)
{
	Array[Size] = value;
	++Size;
}

bool MyVector::empty() const
{
	return Size == 0; //return is a bool value
}

int MyVector::size() const
{
	return Size;
}

int MyVector::capacity() const
{
	return Capacity;
}

bool MyVector::operator==(const MyVector & rhs) const
{
	//if passes thsi then size is equal
	if (size() != rhs.size())
	{
		return false;
	}

	//but another check is for if the elements are different
	for (int i = 0; i < Size; ++i)
	{
		if (Array[i] != rhs.Array[i])
		{
			return false;
		}
	}

	//if it passes the above two condition then only return true
	return true;
	
	//just to understand const type qualifier concept
	//the following call is not allowed since the rhs object has a type qualifier (const) that is not compatible with the member function (not a const type function).
	//rhs.pushBack(); //Illegal!
}

//you just need less than and equal operator definition to overload, others can be derived from that
bool MyVector::operator!=(const MyVector & rhs) const
{
	return !(*this != rhs); //*this is the reference to my vector and rhs is referenece to the vetor instance that i want to compare with
}

std::ostream & operator<<(std::ostream& ostr, const MyVector & rhs)
{
	for (int i = 0; i < rhs.Size; ++i)
	{
		ostr << rhs.Array[i]<<" ";
	}

	ostr << " || ";
	for (int i = rhs.Size; i < rhs.Capacity; ++i)
	{
		ostr << rhs.Array[i] << " ";
	}

	ostr <<std::endl;
	return ostr;
}
