#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <chrono>
#include "Graph.h"
using namespace std;

void HandleFailFileOpen(ios& file)
{
	if (!file.good())
	{
		cout << "The File could not open!";
		exit(1);
	}
}

void HandleWrongInput()
{
	cout << "invalid input";
	exit(1);
}

bool IsInRange(int num, int min, int max)
{
	return (num >= min && num <= max);
}

void ReadGraph(Graph& io_Graph)
{
	int x, y;
	while (!cin.eof())
	{
		cin >> x;
		if (!IsInRange(x, 1, io_Graph.GetAmountOfVertex()))
		{
			HandleWrongInput();
		}
		cin >> y;
		if (!IsInRange(y, 1, io_Graph.GetAmountOfVertex()))
		{
			HandleWrongInput();
		}
		io_Graph.AddEdge(x, y);
	}
}

Graph* FindShortestPathFromSToT(Graph graph, int s, int t)
{
	int* dArray = graph.BFS(s);
	int n = graph.GetAmountOfVertex();

	for (int i = 0; i < n; i++)
	{
		node* current = graph.GetAdjList(i)->GetHead();
		while (current != nullptr)
		{
			if (dArray[current->data] != dArray[i] + 1)
			{
				graph.RemoveEdge(i, current->data);
			}
			current = current->next;
		}
	}

	Graph* trasposedGraph = graph.Transpose(); //g^t
	int* dArrayTrasposed = trasposedGraph->BFS(t);

	for (int i = 0; i < n; i++)
	{
		if (dArrayTrasposed[i] == Graph::inf)
		{
			node* current = trasposedGraph->GetAdjList(i)->GetHead();
			while (current != nullptr)
			{
				graph.RemoveEdge(i, current->data);
				current = current->next;
			}
		}
	}//now g^t=h^t

	return trasposedGraph->Transpose(); //h

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
	Graph graph(n);
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
	ofstream myfile("Measure.txt"); // The name of the file
	HandleFailFileOpen(myfile);

	myfile << "Time taken by function <name-of-fun> is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

}