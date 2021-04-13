#include "BST.h"

void BST::insert(numbersClass* newNumber)
{
	if (root == NULL)
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
			current = current->leftChild;
			if (current == NULL)
			{
				parent->leftChild = newNumber;
				return;
			}
		}
		else
		{
			current = current->rightChild;
			if (current == NULL)
			{
				parent->rightChild = newNumber;
				return;
			}
		}
	}
}

numbersClass* BST::search(int numberID, bool showSearchPath)
{
	if (root == NULL)
	{
		return NULL;
	}

	numbersClass* current = root;

	while (current->numberID != numberID)
	{


		if (showSearchPath)
			cout << current->numberID << " " << current->name << endl;

		if (numberID < current->numberID)
		{
			//go left
			current = current->leftChild;
		}
		else
		{
			//go right
			current = current->rightChild;
		}

		//if current is NULL, search studentID cannot be found
		if (current == NULL)
		{
			return NULL;
		}

	}

	return current;
}


void BST::inOrderTraversal(numbersClass* current)
{
	if (current != NULL)
	{
		inOrderTraversal(current->leftChild);
		cout << current->numberID << " " << current->name << endl;
		inOrderTraversal(current->rightChild);
	}
}

void BST::preOrderTraversal(numbersClass* current)
{
	if (current != NULL)
	{
		cout << current->numberID << " " << current->name << endl;
		preOrderTraversal(current->leftChild);
		preOrderTraversal(current->rightChild);
	}
}

void BST::postOrderTraversal(numbersClass* current)
{
	if (current != NULL)
	{
		postOrderTraversal(current->leftChild);
		postOrderTraversal(current->rightChild);
		cout << current->numberID << " " << current->name << endl;
	}
}