#pragma once
#include <iostream>
#include <string>

using namespace std;


class numbersClass
{
	public:
		int numberID;
		string name;
		numbersClass* leftChild;
		numbersClass* rightChild;

		numbersClass(int numberID, string name);

};

