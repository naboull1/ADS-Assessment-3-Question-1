#pragma once
#include "numbersClass.h"


class BST
{
	public:
		numbersClass* root = NULL;
		virtual void insert(numbersClass* newNumber);
		numbersClass* search(int numberID, bool showSearchPath = false);
};

