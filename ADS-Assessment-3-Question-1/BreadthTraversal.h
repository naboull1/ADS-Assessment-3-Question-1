#pragma once
#include <queue>
#include "numbersClass.h"


//HELPER CLASS FOR OUTPUT
class LevelNodeClass {
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


class BreadthTraversal
{
	public:
		numbersClass* root = NULL;
		virtual void insert(numbersClass* newNumber);
		numbersClass* search(int numberID, bool showSearchPath = false);

		//show
		void show(numbersClass* p);
};

