#pragma once
#include "Node.h"

class Dijkstra
{
private:
	int numNodes;
	int totalCost;
	Node** nodes;
	int* visited; //the path
	int* unvisited;
	void addVisited(int Id);

public:
	Dijkstra(int nodes, Node** allNodes);
	int getBestPath(Node* start, Node* dest);
	Node* getNode(int Id);
	int* getPath();

};