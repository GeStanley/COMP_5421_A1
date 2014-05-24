/*
 * IntList.cpp
 *
 *  Created on: May 10, 2014
 *      Author: Geoffrey
 */

#include <iostream>
#include "IntList.h"
using namespace std;

IntList::IntList()
{

	capacity = 1;
	size = 0;

	lineNumbers = new int[capacity];

}

//IntList::IntList( const IntList& list )
//{
//	//capacity = list.getCapacity();
//	//size = list.getSize();
//	cout << "copying int list object" << endl;
//}

IntList::~IntList()
{
	//cout << "Destroying int list object" << endl;
}

bool IntList::isEmpty()
{
	if(size==0)
		return true;
	else
		return false;
}

bool IntList::contains(int element)
{
	for(int i=0; i<size; i++)
	{
		if(lineNumbers[i] == element)
			return true;
	}

	return false;
}

void IntList::append(const int element)
{

	bool found = false;
	int i = 0;

	while (i < size)
	{
		if (lineNumbers[i] == element)
			found = true;

		i++;
	}

	if (!found){
		if (size == capacity)
			doubleCapacity();

		lineNumbers[size] = element;

		size++;
	}
}

int IntList::getElement(int location)
{
	return lineNumbers[location];
}

void IntList::setElement(int location, int element)
{
	lineNumbers[location] = element;
}

int IntList::getSize()
{
	return size;
}

int IntList::getCapacity()
{
	return capacity;
}

void IntList::printArray( ostream& stream )
{
	for(int i=0; i<capacity; i++)
		stream << "data at location " << i <<  " is : " << lineNumbers[i] << endl;
}

const int* IntList::getReadOnlyPointer()
{

	//TODO Make read-only

	return lineNumbers;
}

void IntList::doubleCapacity()
{

	capacity *= 2;

	int *temp = new int[capacity];

	for(int i=0; i<size; i++)
		temp[i] = *(lineNumbers + i);

	lineNumbers = new int[capacity];
	lineNumbers = temp;

}
