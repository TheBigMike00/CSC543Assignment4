#include <iostream>
#include "Dijkstra.h"

int main()
{
    //Node '1' Initialization
    int** edges1 = new int* [2];
    for (int i = 0; i < 2; i++)
    {
        edges1[i] = new int[2];
    }
    edges1[0][0] = 2;
    edges1[0][1] = 10;

    edges1[1][0] = 5;
    edges1[1][1] = 3;
    Node* node1= new Node(1, edges1, 2);


    //Node '2' Initialization
    int** edges2 = new int* [2];
    for (int i = 0; i < 2; i++)
    {
        edges2[i] = new int[2];
    }
    edges2[0][0] = 3;
    edges2[0][1] = 2;

    edges2[1][0] = 5;
    edges2[1][1] = 4;
    Node* node2 = new Node(2, edges2, 2);


    //Node '3' Initialization
    int** edges3 = new int* [1];
    for (int i = 0; i < 1; i++)
    {
        edges3[i] = new int[2];
    }
    edges3[0][0] = 4;
    edges3[0][1] = 9;
    Node* node3 = new Node(3, edges3, 1);


    //Node '4' Initialization
    int** edges4 = new int* [1];
    for (int i = 0; i < 1; i++)
    {
        edges4[i] = new int[2];
    }
    edges4[0][0] = 3;
    edges4[0][1] = 7;
    Node* node4 = new Node(4, edges4, 1);


    //Node '5' Initialization
    int** edges5 = new int* [3];
    for (int i = 0; i < 3; i++)
    {
        edges5[i] = new int[2];
    }
    edges5[0][0] = 2;
    edges5[0][1] = 1;

    edges5[1][0] = 3;
    edges5[1][1] = 8;

    edges5[2][0] = 4;
    edges5[2][1] = 2;
    Node* node5 = new Node(5, edges5, 3);

    //put initialized nodes in a list
    Node* nodes[5] = { node1, node2, node3, node4, node5 };


    //let the magic happen
    Dijkstra* pleaseWork = new Dijkstra(5, nodes);
    int cost = pleaseWork->getBestPath(node1, node2);
    std::cout << "Cost: "<<cost << "\n";

    int* finalPath = pleaseWork->getPath();
    for (int i = 0; i < 5; i++)
    {
        std::cout << finalPath[i] << " ";
    }
    std::cout << "\n\n";
    
}