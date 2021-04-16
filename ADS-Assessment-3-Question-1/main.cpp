/// Luaay Naboulsi
/// ADS103 Algorithmsand Data Structures
/// Assessment 3 Question 1

#include <iostream>
#include <string>
#include <windows.h>								//Library for controling windows functions
#include <fstream>									//Library for File System control
#include "BreadthTraversal.h"

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
	


	//Writes the result to a text file
	ofstream  writeFile;
	writeFile.open("output-a1q1.txt");
	writeFile << " ";
	cout << endl;
	writeFile.close();


	BreadthTraversal textList;

	for (int i = 0; i < firstLineVariable; i++)
	{
		readFile >> secondLineVariable;
		textList.insert(new numbersClass(secondLineVariable));
	}

	textList.show(textList.root);



	//StudentNode* sNodePtr = new StudentNode(123, "asasd");
	//bst1.insert(new numbersClass(3433, "Jeff"));
	//bst1.insert(new numbersClass(2222, "Bill"));
	//bst1.insert(new numbersClass(1221, "Trevor"));
	//bst1.insert(new numbersClass(4533, "Uncle"));
	//bst1.insert(new numbersClass(3333, "Adam"));
	//bst1.insert(new numbersClass(6666, "Bridge"));
	//bst1.insert(new numbersClass(7777, "Bam"));
	//bst1.insert(new numbersClass(4343, "Bucket"));

	//bst1.show(bst1.root);




	system("pause");








}