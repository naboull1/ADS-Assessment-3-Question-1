#pragma once
#include <iostream>
#include <list>

using namespace std;

class Graph {
public:
	int numVertices;
	list<int>* adjLists;
	bool* visited;


	Graph(int vertices);
	void addEdge(int src, int dest);
	void BFS(int startVertex);
};

