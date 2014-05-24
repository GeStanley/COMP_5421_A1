/*
 * WordData.h
 *
 *  Created on: May 10, 2014
 *      Author: Geoffrey
 */

#ifndef WORDDATA_H_
#define WORDDATA_H_

#include <iostream>
#include <string>
#include "IntList.h"
//#include namespace std;

class WordData
{
public:
	WordData( std::string, int );
	//WordData( const WordData& data );//copy constructor
	//WordData& operator=( const WordData& data );//copy assignment operator
	~WordData();
	void addLineNumber( int );
	int getFrequency();
	//read only pointer to stored word
	//read only reference to the intlist
	int compare( std::string );
	void print( std::ostream & );

private:
	char *word;
	int frequency;
	IntList list;

};



#endif /* WORDDATA_H_ */
