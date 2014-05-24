/*
 * wordListDriver.cpp
 *
 *  Created on: May 10, 2014
 *      Author: Geoffrey
 */
#include <iostream>
using namespace std;
#include "WordList.h"
#include "IntList.h"

int main()
{
	WordList wl("input.txt");
	wl.print(cout);

	//WordData wd("testing", 1);
	//wd.addLineNumber(3);
	//wd.addLineNumber(7);
	//wd.print(cout);

	//IntList il;
	//il.append(1);
	//il.append(2);
	//il.append(6);
	//il.printArray(cout);

	return 0;
}



