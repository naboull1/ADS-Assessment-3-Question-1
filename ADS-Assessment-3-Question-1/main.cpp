/// Luaay Naboulsi
/// ADS103 Algorithmsand Data Structures
/// Assessment 3 Question 1

#include <iostream>
#include <string>
#include <windows.h>								//Library for controling windows functions
#include <fstream>									//Library for File System control
#include <chrono>									//Library for Time Control
#include <cstdlib>
#include <ctime>
#include "BST.h"
#include "AVL.h"
//#include "BFT.h"
#include <map>
#include<queue>
#include<list>


using namespace std;


template<typename T>
class Graph {

	map<T, list<T> > adjList;

public:
	Graph() {

	}
	void addEdge(T u, T v, bool bidir = true) {

		adjList[u].push_back(v);
		if (bidir) {
			adjList[v].push_back(u);
		}
	}

	void print() {

		//Iterate over the map
		for (auto i : adjList) {
			cout << i.first << "->";

			//i.second is LL
			for (T entry : i.second) {
				cout << entry << ",";
			}
			cout << endl;
		}
	}

	void bfs(T src) {

		queue<T> q;
		map<T, bool> visited;

		q.push(src);
		visited[src] = true;

		while (!q.empty()) {

			T node = q.front();
			cout << node << " ";
			q.pop();

			// For the neigbours of the current node, find out the nodes which are not visited
			for (int neigbour : adjList[node]) {
				if (!visited[neigbour]) {
					q.push(neigbour);
					visited[neigbour] = true;
				}
			}
		}
	}
};




//Main Master Code
void main()
{
	//BST bst1;
	////StudentNode* sNodePtr = new StudentNode(123, "asasd");
	//bst1.insert(new numbersClass(3433, "Jeff"));
	//bst1.insert(new numbersClass(2222, "Bill"));
	//bst1.insert(new numbersClass(1221, "Trevor"));
	//bst1.insert(new numbersClass(4533, "Uncle"));
	//bst1.insert(new numbersClass(3333, "Adam"));
	//bst1.insert(new numbersClass(6666, "Bridge"));
	//bst1.insert(new numbersClass(7777, "Bam"));
	//bst1.insert(new numbersClass(4343, "Bucket"));

	//cout << "try find student matching id 1221..." << endl;
	//numbersClass* sPtr = bst1.search(1221, true);

	//if (sPtr == NULL)
	//	cout << "Cannot find a student matching id 1221" << endl;
	//else
	//	cout << "Found " << sPtr->name << " with id 1221" << endl;


	//cout << "Students inorder traversal" << endl;
	//cout << "==========================" << endl;
	//bst1.inOrderTraversal(bst1.root);

	//cout << "Students preorder traversal" << endl;
	//cout << "===========================" << endl;
	//bst1.preOrderTraversal(bst1.root);

	//cout << "Students postorder traversal" << endl;
	//cout << "===========================" << endl;
	//bst1.postOrderTraversal(bst1.root);

	//cout << endl << endl;
	//cout << "AVL" << endl;
	//cout << "===" << endl;
	//AVL avl1;
	//avl1.displayRotations = true;
	//avl1.insert(new numbersClass(2333, "Jeff"));
	//avl1.insert(new numbersClass(2222, "Bill"));
	//avl1.insert(new numbersClass(1221, "Trevor"));
	//cout << "Tree height thus far: " << avl1.height(avl1.root) << endl;
	//avl1.insert(new numbersClass(4533, "Uncle"));
	//avl1.insert(new numbersClass(3333, "Adam"));
	//avl1.insert(new numbersClass(6666, "Bridge"));
	//avl1.insert(new numbersClass(7777, "Bam"));
	//avl1.insert(new numbersClass(4343, "Bucket"));
	//cout << "AVL ROOT : " << avl1.root->name << " " << avl1.root->numberID << endl;
	//cout << "Students AVL inorder traversal" << endl;
	//cout << "==============================" << endl;
	//avl1.inOrderTraversal(avl1.root);


	//cout << "try find student matching id 4343..." << endl;
	//numbersClass* sPtr2 = avl1.search(4343, true);
	//if (sPtr2 != NULL)
	//	cout << "Found " << sPtr2->name << " with id 4343" << endl;
	//else
	//	cout << "Cannot find id 4343 in avl1 tree" << endl;





	//Graph g(4);
 // g.addEdge(0, 1);
 // g.addEdge(0, 2);
 // g.addEdge(1, 2);
 // g.addEdge(2, 0);
 // g.addEdge(2, 3);
 // g.addEdge(3, 3);

 // g.BFS(2);





	Graph<int> g;


	g.addEdge(5, 8);
	g.addEdge(8, 10);
	g.addEdge(10, 11);
	g.addEdge(11, 12);
	g.addEdge(12, 17);
	g.addEdge(17, 21);
	g.addEdge(21, 23);
	g.addEdge(23, 8);

	g.bfs(5);


	system("pause");


	////Declaration of Variables
	//int firstLineVariable;
	//int secondLineVariable;

	////Reads in textfile and stores information into Variables
	//ifstream readFile;
	//readFile.open("input-q1a2.txt");
	//readFile >> firstLineVariable;
	//readFile >> secondLineVariable;


	////Writes the result to a text file
	//ofstream  writeFile;
	//writeFile.open("output-a1q1.txt");
	//writeFile << " ";
	//cout << endl;
	//writeFile.close();





}