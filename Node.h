#pragma once

class Node
{
private:
	int distance;
	int Id;
	int numConnections;
	int** matrixOfEdges; //[Node Id][weight]


public:
	Node(int id, int** matrix, int numConns);
	int getDistance();
	void setDistance(int val);
	int getId();
	int getNumConnections();
	int** getMatrix();

};