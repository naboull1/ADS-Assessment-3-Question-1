#include "BST.h"

void BST::insert(numbersClass* newNumber)
{
	if (root = NULL)
	{
		root = newNumber;
		return;
	}

	numbersClass* current = root;
	numbersClass* parent = NULL;

	while (true)
	{
		parent = current;

		if (newNumber->numberID < current->numberID)
		{

		}
	}
}

numbersClass* BST::search(int numberID, bool showSearchPath)
{

    return nullptr;
}
