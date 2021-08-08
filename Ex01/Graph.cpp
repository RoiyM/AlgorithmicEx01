#include "Graph.h"
#include "Queue.h"
#include "List.h"
#include<iostream>
using namespace std;

Graph::Graph(int n)
{
	m_NumberOfVertex = n;
	MakeEmptyGraph();
}

Graph::~Graph()
{
	for (int i = 1; i <= m_NumberOfVertex; i++)
	{
		delete m_Graph[i];
	}

	delete[] m_Graph;
}

Graph* Graph::Transpose()
{
	Graph* transposedGraph = new Graph(m_NumberOfVertex+1);

	for (int i = 1; i <= m_NumberOfVertex; i++)
	{
		node* current = this->GetAdjList(i)->GetHead();
		while (current != nullptr)
		{
			transposedGraph->AddEdge(current->data, i);
			current = current->next;
		}
	}

	return transposedGraph;
}

bool Graph::IsEmpty()
{
	return m_NumberOfVertex == 0;
}


void Graph::PrintGraph()
{
	bool hasPrintedALine = false;
	for (int i = 1; i <= m_NumberOfVertex; i++)
	{
		node* current = m_Graph[i]->GetHead();
		while (current != nullptr)
		{
			hasPrintedALine = true;
			cout << "(" << i << "," << current->data << ") ";
			current = current->next;
		}
		if(hasPrintedALine)
		{ 
			cout << endl;
		}
		hasPrintedALine = false;
	}
}


void Graph::MakeEmptyGraph()
{
	m_Graph = new List * [m_NumberOfVertex+1];
	m_Graph[0] = nullptr;
	for (int i = 1; i <= m_NumberOfVertex; i++)
	{
		m_Graph[i] = new List();
	}
}

int Graph::GetAmountOfVertex()
{
	return m_NumberOfVertex;
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
	int* dArray = new int[m_NumberOfVertex+1];
	int* pArray = new int[m_NumberOfVertex+1];
	for (int i = 1; i <= m_NumberOfVertex; i++)
	{
		dArray[i] = inf;
		pArray[1] = inf;
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
				pArray[current->data] = u;
				queue.Enqueue(current->data);
			}
			current = current->next;
		}
	}

	delete[] pArray;
	return dArray;
}