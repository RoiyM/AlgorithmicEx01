#include "Graph.h"

Graph::Graph(int n)
{
	MakeEmptyGraph(n);
}

void Graph::MakeEmptyGraph(int n)
{
	m_Graph = new List * [n];
	for (int i = 0; i < n; i++)
	{
		m_Graph[i] = new List();
	}
}


bool Graph::IsAdjacent(int u, int v)
{
	bool isAdjacent = false;
	node* currentNode = m_Graph[u]->GetHead();
	while (currentNode != nullptr && !isAdjacent)
	{
		if (currentNode->data == v)
		{
			isAdjacent = true;
		}
	}
	
	return isAdjacent;
}

List* Graph::GetAdjList(int u)//החזרת רשימה מקושרת של השכנים של קדקוד.u
{
	return m_Graph[u];
}

void Graph::AddEdge(int u, int v)// (u, v) הוספת קשת
{
	m_Graph[u]->AddToTail(v);
}
void Graph::RemoveEdge(int u, int v)// .(מהגרףu, v)  – הסרת הקשת
{
	m_Graph[u]->DeleteItem(v);
}