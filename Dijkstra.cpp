#include "Dijkstra.h"
#include <limits>

Dijkstra::Dijkstra(int nodes, Node** allNodes)
{
	this->numNodes = nodes;
	this->nodes = allNodes;
	this->totalCost = 0;

	this->unvisited = new int[this->numNodes];
	for (int i = 0; i < this->numNodes; i++)
	{
		this->unvisited[i] = this->nodes[i]->getId();
	}

	this->visited = new int[this->numNodes];
	for (int i = 0; i < this->numNodes; i++)
	{
		this->visited[i] = 0;
	}
}

void Dijkstra::addVisited(int Id)
{
	for (int i = 0; i < this->numNodes; i++)
	{
		if (this->visited[i] == 0)
		{
			this->visited[i] = Id;
			break;
		}
	}
}

int Dijkstra::getBestPath(Node* start, Node* dest)
{
	//observe all unvisited neiboring nodes of starting node

	//calculate distance by adding totalCost to edgeVal of each unvisited node - add smallest to path

	//mark current node as visited, mark node with smallest distance as the currNode

	Node* currNode = start;
	Node* tempNode = start;
	int smallestDistance = std::numeric_limits<int>::max();

	int iterations = currNode->getNumConnections();
	for (int i = 0; i < iterations; i++)
	{
		int tempDistance = currNode->getDistance();

		if (tempDistance > currNode->getMatrix()[i][1])
		{
			tempDistance = currNode->getMatrix()[i][1];
			getNode(currNode->getMatrix()[i][0])->setDistance(tempDistance);
		}


		if (tempDistance < smallestDistance)
		{
			smallestDistance = tempDistance;
			tempNode = getNode(currNode->getMatrix()[i][0]);
		}
	}

	this->totalCost += smallestDistance;
	addVisited(currNode->getId());

	if (tempNode->getId() == dest->getId())
	{
		addVisited(tempNode->getId());
		return this->totalCost;
	}
	else
		return getBestPath(tempNode, dest);
}

Node* Dijkstra::getNode(int Id)
{
	for (int i = 0; i < this->numNodes; i++)
	{
		if (this->nodes[i]->getId() == Id)
			return this->nodes[i];
	}
	return nullptr;
}

int* Dijkstra::getPath()
{
	return this->visited;
}
