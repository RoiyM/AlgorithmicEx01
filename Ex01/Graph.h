#pragma once
#include "List.h"
class Graph
{
private:
	List** m_Graph;
	int m_NumberOfVertex; //n

public :
	int static const inf = -1;
	//ctor
	Graph(int n);

	//dtor
	~Graph();

	//returns if the graph is empty
	bool IsEmpty();

	//output: prints all the edes of the graph
	void PrintGraph();

	//makes an empty graph
	void MakeEmptyGraph(); 

	//output:returns the numbers of vertex
	int GetAmountOfVertex();

	//output: return the trasposed graph
	Graph* Transpose();

	//input: vertex u, vertex v
	//output: return if there is an edge between u and v
	bool IsAdjacent(int u, int v); 

	//input: vertex u
	//output: return the Adjacent List of u
	List* GetAdjList(int u); 

	//input: vertex u, vertex v
	//adds an edge between u and v
	void AddEdge(int u, int v);

	//input: vertex u, vertex v
	//delete the edge (u,v)
	void RemoveEdge(int u, int v);

	//input: vertex u
	//
	int* BFS(int s);
};