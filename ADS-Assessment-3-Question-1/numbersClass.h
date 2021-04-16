#pragma once
#include <iostream>
#include <string>

using namespace std;


class numbersClass
{
	public:
		int numberID;
		numbersClass* leftChild;
		numbersClass* rightChild;

		numbersClass(int numberID);
};

