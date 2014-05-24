/*
 * IntList.h
 *
 *  Created on: May 10, 2014
 *      Author: Geoffrey
 */

#ifndef INTLIST_H_
#define INTLIST_H_

class IntList
{
public:
	IntList();
	//IntList( const IntList& list );//copy constructor
	//IntList& operator=( const IntList& list );//copy assignment operator
	~IntList();
	bool isEmpty();
	bool contains( int );
	void append( const int );
	int getElement(int location);
	void setElement(int location, int element);
	int getSize();
	int getCapacity();
	void printArray( std::ostream & );
	const int* getReadOnlyPointer();
private:

	int *lineNumbers;
	int size;
	int capacity;

	void doubleCapacity();
};



#endif /* INTLIST_H_ */
