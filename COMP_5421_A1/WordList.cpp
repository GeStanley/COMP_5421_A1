/*
 * WordList.cpp
 *
 *  Created on: May 10, 2014
 *      Author: Geoffrey
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "WordList.h"
#include "WordData.h"

using namespace std;

WordList::WordList(std::string fileName)
{

	cout << "Building word list" << endl;

	sourceFile = fileName;
	size = 0;

	ifstream inputFile;
	inputFile.open("input.txt");


	string line;

	getline(inputFile, line);
	int lineCount = 1;

	while (!inputFile.fail())
	{
		cout << line << endl;

		istringstream sin(line);
		string word = "";

		while (sin >> word){
		
			
			cout << word << endl;

			if(size==0)
			{
				cout << "creating the first node" << endl;

				WordData currentWord(word, lineCount);
				lastNode = new WordNode( currentWord, NULL );
				firstNode = lastNode;
			}
			else
			{

				WordData *searchResult = search(word);
				
				if (searchResult != NULL)
				{
					searchResult->addLineNumber(lineCount);
				}
				else
				{
					WordData currentWord(word, lineCount);
					firstNode = new WordNode(currentWord, firstNode);
				}
			}

			size++;
		}

		getline(inputFile, line);
		lineCount++;
	}
}

void WordList::print( ostream& stream)
{
	stream << "Word CollectionSource File: " << sourceFile << endl;
	stream << "============================" << endl;

	WordNode *current = firstNode;

	while(current!=NULL)
	{
		current->data.print(stream);

		stream << endl;

		current = current->nextNode;

	}

}

int WordList::getSize()
{
	return size;
}

WordData* WordList::search( string word)
{
	WordNode *current = firstNode;

	while (current != NULL)
	{
		int result = current->data.compare(word);

		if (result == 0)
			return &current->data;

		current = current->nextNode;
	}

	return NULL;
}
