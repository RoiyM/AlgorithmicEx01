#pragma once
#include "List.h"
class Graph
{
private:
	List** m_Graph;
public :
	Graph(int n);

	//input: amount of vertex n
	void MakeEmptyGraph(int n); 

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
	void BFS(int u);
};

