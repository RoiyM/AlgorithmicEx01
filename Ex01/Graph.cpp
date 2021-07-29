#include "Graph.h"
#include "Queue.h"
#include "List.h"

Graph::Graph(int n)
{
	m_NumberOfVertex = n;
	MakeEmptyGraph();
}

void Graph::MakeEmptyGraph()
{
	m_Graph = new List * [m_NumberOfVertex];
	for (int i = 0; i < m_NumberOfVertex; i++)
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

List* Graph::GetAdjList(int u)
{
	return m_Graph[u];
}

void Graph::AddEdge(int u, int v)
{
	m_Graph[u]->AddToTail(v);
}

void Graph::RemoveEdge(int u, int v)
{
	m_Graph[u]->DeleteItem(v);
}

int* Graph::BFS(int s)
{
	Queue queue;
	int* dArray = new int[m_NumberOfVertex];
	for (int i = 0; i < m_NumberOfVertex; i++)
	{
		dArray[i] = inf;	
	}

	queue.Enqueue(s);
	dArray[s] = 0;

	while (!queue.IsEmpty())
	{
		int u = queue.Dequeue();
		List* adjList = this->GetAdjList(u);
		node* current = adjList->GetHead();
		while (current != nullptr)
		{
			if (dArray[current->data] == inf)
			{
				dArray[current->data] = dArray[u] + 1;
				queue.Enqueue(current->data);
			}
			current = current->next;
		}

		delete adjList;
	
	}

	return dArray;
}

