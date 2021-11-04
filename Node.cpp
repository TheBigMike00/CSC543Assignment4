#include "Node.h"
#include <limits>

Node::Node(int id, int** matrix, int numConns)
{
	this->Id = id;
	this->matrixOfEdges = matrix;
	this->numConnections = numConns;
	this->distance = std::numeric_limits<int>::max();
}

int Node::getDistance()
{
	return this->distance;
}

void Node::setDistance(int val)
{
	this->distance = val;
}

int Node::getId()
{
	return this->Id;
}

int Node::getNumConnections()
{
	return this->numConnections;
}

int** Node::getMatrix()
{
	return this->matrixOfEdges;
}
