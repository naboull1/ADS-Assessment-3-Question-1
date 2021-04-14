#pragma once
#include "numbersClass.h"


class BST
{
	public:
		numbersClass* root = NULL;
		virtual void insert(numbersClass* newNumber);
		numbersClass* search(int numberID, bool showSearchPath = false);

		//recursive traversal functions
		void inOrderTraversal(numbersClass* current);
		void preOrderTraversal(numbersClass* current);
		void postOrderTraversal(numbersClass* current);
};

