#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <chrono>
#include "Graph.h"
using namespace std;

void HandleWrongInput()
{
	cout << "invalid input";
	exit(1);
}

bool IsInRange(int num, int min, int max)
{
	return (num >= min && num <= max);
}

void ReadGraph(Graph* io_Graph)
{
	int x, y;
	while (!cin.eof())
	{
		cin >> x;
		if (!IsInRange(x, 1, io_Graph->GetAmountOfVertex()))
		{
			HandleWrongInput();
		}
		cin >> y;
		if (!IsInRange(y, 1, io_Graph->GetAmountOfVertex()))
		{
			HandleWrongInput();
		}
		if (cin.eof())
		{
			break;
		}
		io_Graph->AddEdge(x, y);
	}
}

Graph* FindShortestPathFromSToT(Graph* graph, int s, int t)
{
	int* dArray = graph->BFS(s);
	int n = graph->GetAmountOfVertex();
	
	for (int i = 1; i <= n; i++)
	{
		node* current = graph->GetAdjList(i)->GetHead();
		while (current != nullptr)
		{
			if (dArray[current->data] != dArray[i] + 1)
			{
				node* prev = current;
				current = current->next;
				graph->RemoveEdge(i, prev->data);
			}
			else
			{
				current = current->next;
			}
		}
	}//now g has become g_s

	Graph* trasposedGraph = graph->Transpose(); //g_s^t
	int* dArrayTrasposed = trasposedGraph->BFS(t);

	for (int i = 1; i <= n; i++)
	{
		if (dArrayTrasposed[i] == Graph::inf)
		{
			node* current = trasposedGraph->GetAdjList(i)->GetHead();
			while (current != nullptr)
			{
				node* prev = current;
				current = current->next;
				trasposedGraph->RemoveEdge(i, prev->data);
			}
		}
	}//now g_h^t has become h^t

	Graph* hTransposeGraph = trasposedGraph->Transpose();//h

	delete trasposedGraph;

	return hTransposeGraph; 
}

int main()
{
	int n, s, t;
	cin >> n;
	cin >> s;
	cin >> t;

	if (n < 0 || !IsInRange(t, 1, n) || !IsInRange(s, 1, n))
	{
		HandleWrongInput();
	}
	Graph* graph = new Graph(n);
	ReadGraph(graph);

	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	Graph* resGraph = FindShortestPathFromSToT(graph, s, t);
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	
	cout << "Time taken by function <FindShortestPathFromSToT> is : " << fixed
		<< time_taken << setprecision(9) << " sec" << endl;

	resGraph->printGraph();
	delete graph;
	delete resGraph;
}