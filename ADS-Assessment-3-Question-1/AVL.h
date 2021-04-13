#pragma once
#include "BST.h"


class AVL :
    public BST
{
public:
    bool displayRotations = true;
    int height(numbersClass* node);
    int difference(numbersClass* node);

	numbersClass* RRrotation(numbersClass* parent);
	//left branch, left child
	numbersClass* LLrotation(numbersClass* parent);
	//left branch, right child
	numbersClass* LRrotation(numbersClass* parent);
	//right branch, left child
	numbersClass* RLrotation(numbersClass* parent);


	numbersClass* balance(numbersClass* parent);


	numbersClass* insertAVL(numbersClass* parent, numbersClass* newNumber);

	void insert(numbersClass* newNumber);

};

