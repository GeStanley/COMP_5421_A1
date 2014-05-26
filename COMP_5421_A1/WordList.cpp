/*
 * WordList.cpp
 *
 *  Created on: May 10, 2014
 *      Author: Geoffrey
 */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "WordList.h"
#include "WordData.h"

using namespace std;

WordList::WordList( std::string fileName )
{

	cout << "Building word list" << endl;

	sourceFile = fileName;
	size = 0;

	fstream fileStream;
	fileStream.open("input.txt");

	load(fileStream);
}

void WordList::print( ostream &stream)
{
	char previousLetter = ' ';
	char letter = '`';
	stream << "Word CollectionSource File: " << sourceFile << endl;
	stream << "============================" << endl;

	WordNode *current = firstNode;

	while(current!=NULL)
	{
		
		
		const char *word = current->data.getWord();
		previousLetter = tolower(word[0]);

		while (letter != previousLetter)
		{
			letter++;
			stream << "<" << (char)toupper(letter) << ">" << endl;
		}

		current->data.print(stream);

		current = current->nextNode;

	}

	while (letter < 'z')
	{
		letter++;
		stream << "<" << (char)toupper(letter) << ">" << endl;
	}

}

int WordList::getSize()
{
	return size;
}

void WordList::load(std::fstream &fileStream)
{
	string line;

	getline(fileStream, line);
	int lineCount = 1;

	while (!fileStream.fail())
	{
		cout << line << endl;

		istringstream sin(line);
		string word = "";

		while (sin >> word){

			cout << word << endl;

			word.erase(
				std::remove_if(word.begin(), word.end(), &ispunct),
				word.end());

			cout << word << endl;

			insert(word, lineCount);
		}

		getline(fileStream, line);
		lineCount++;
	}
}

void WordList::insert(string word, int line)
{
	
	if (size == 0)
	{
		cout << "creating the first node" << endl;

		WordData currentWord(word, line);
		lastNode = new WordNode(currentWord, NULL);
		firstNode = lastNode;
		size++;
	}
	else
	{

		WordNode *current = firstNode;
		WordNode *previous=NULL;

		while (current != NULL)
		{
			int result = current->data.compare(word);

			if (result == 0)
			{//node containing the same word found, adding line number.
				current->data.addLineNumber(line);
				size++;
				return;
			} 
			else if(result<0)
			{
				cout << "inserting a node into the middle of the list..." << endl;
				WordData currentWord(word, line);

				if (previous != NULL)
				{
					previous->nextNode = new WordNode(currentWord, current);
				}
				else
				{
					firstNode = new WordNode(currentWord, current);
				}
				size++;
				return;
			}

			
			previous = current;
			current = current->nextNode;
		}

		WordData currentWord(word, line);
		lastNode = new WordNode(currentWord, NULL);
		previous->nextNode = lastNode;

		size++;
	}
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
