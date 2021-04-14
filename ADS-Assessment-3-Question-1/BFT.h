#pragma once
#include <iostream>
#include <list>

using namespace std;

class Graph {
	int numVertices;
	list<int>* adjLists;
	bool* visited;

public:
	Graph(int vertices);
	void addEdge(int src, int dest);
	void BFS(int startVertex);
};

