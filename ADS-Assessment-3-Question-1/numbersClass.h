#pragma once
#include <iostream>
#include <string>

using namespace std;

// Class to carry variables for nodes and deciding left or right
class numbersClass
{
	public:
		int numberID;
		numbersClass* leftChild;
		numbersClass* rightChild;

		numbersClass(int numberID);
};

