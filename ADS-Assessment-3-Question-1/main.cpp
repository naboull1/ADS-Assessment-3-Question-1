/// Luaay Naboulsi
/// ADS103 Algorithmsand Data Structures
/// Assessment 3 Question 1

#include <iostream>
#include <string>
#include <windows.h>								//Library for controling windows functions
#include <fstream>									//Library for File System control
#include "BreadthTraversal.h"						//Header file that contains Pointesr and defines variables for breadthTraversal

using namespace std;

//Main Master Code
void main()
{
	//Declaration of Variables
	int firstLineVariable = 0;
	int secondLineVariable;

	//Reads in textfile and stores information into Variables
	ifstream readFile;
	readFile.open("input-q1a2.txt");
	readFile >> firstLineVariable;

	//create array
	BreadthTraversal textList;

	//Cycle through textfile adding numbers to textlist array
	for (int i = 0; i < firstLineVariable; i++)
	{
		readFile >> secondLineVariable;
		textList.insert(new numbersClass(secondLineVariable));
	}

	//show text list to console
	textList.show(textList.root);



	system("pause");








}