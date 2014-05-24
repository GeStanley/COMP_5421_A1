/*
 * WordList.h
 *
 *  Created on: May 10, 2014
 *      Author: Geoffrey
 */

#ifndef WORDLIST_H_
#define WORDLIST_H_

//#include <iostream>
#include "WordData.h"
#include <string>
//using namespace std;

class WordList
{
public:
	WordList( std::string );
	void print( std::ostream & );
	int getSize();

private:
	std::string sourceFile;
	int size;

	void load();
	WordData* search( std::string );
	void insert( std::string );

	struct WordNode
	{
		WordData data;
		WordNode *nextNode;

		WordNode( WordData newData, WordNode *newPointer ) :
				data(newData), nextNode(newPointer){}

	} *firstNode, *lastNode;
};

#endif /* WORDLIST_H_ */
