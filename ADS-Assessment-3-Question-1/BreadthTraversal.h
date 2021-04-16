#pragma once
#include <queue>
#include "numbersClass.h"


//CLASS for creating levels to seperate numbers 
class LevelNodeClass 
{
public:
	numbersClass* number;
	int level;

	//constructor
	LevelNodeClass(numbersClass* number, int level)
	{
		this->number = number;
		this->level = level;
	}
};

//Class to pass variable data to functions
class BreadthTraversal
{
	public:
		numbersClass* root = NULL;
		virtual void insert(numbersClass* newNumber);
		numbersClass* search(int numberID, bool showSearchPath = false);

		//performs breadth traversal
		void show(numbersClass* p);
};

