/*
 * WordData.cpp
 *
 *  Created on: May 10, 2014
 *      Author: Geoffrey
 */

#include <iostream>
#include <cstring>
#include "string.h"
#include "WordData.h"
using namespace std;

WordData::WordData( std::string wordString, int line )
{

	frequency = 1;

	//list = new IntList;
	list.append(line);
	
	word = new char [wordString.length()+1];

	strcpy_s (word, wordString.length()+1, wordString.c_str());

}

WordData::~WordData()
{
	//cout << "Destroying word data object" << endl;
}

void WordData::addLineNumber( int line )
{
	frequency++;
	list.append(line);
}

const char* WordData::getWord()
{
	return word;
}

const IntList* WordData::getLineList()
{
	return &list;
}

int WordData::getFrequency()
{
	return frequency;
}

int WordData::compare( std::string compString )
{

	char *comparable = new char [compString.length()+1];
	strcpy_s(comparable, compString.length()+1, compString.c_str());

	int i=0;

	while(word[i]!=0 && comparable[i]!=0)
	{
		char source = tolower(word[i]);
		char input = tolower(comparable[i]);

		if (source - input < 0)
		{
			cout << "1" << endl;
			return 1;
		}
		if (source - input > 0)
		{
			cout << "-1 here" << endl;
			return -1;
		}
		i++;
	}

	if (word[i] == 0 && comparable[i] == 0)
	{
		cout << "0" << endl; 
		return 0;
	}
	else if (word[i] == 0)
	{
		cout << "1" << endl;
		return 1;
	}
	else if (comparable[i] == 0)
	{
		cout << "-1" << endl;
 		return -1;
	}
	return 999;
}

void WordData::print( ostream& stream )
{

	int spacing = 15;
	int i=0;
	string wordString;

	while(word[i]!=0)
	{
		wordString += word[i];
		i++;
		spacing--;
	}

	while (spacing > 0){
		stream << " ";
		spacing--;
	}

	stream << word;

	stream << " (" << frequency << ") ";

	const int *lines = list.getArray();


	for (int i = 0; i < list.getSize(); i++)
		stream << lines[i] << " " ;

	stream << endl;
}
