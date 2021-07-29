#include <iostream>
#include <fstream>
#include <string>
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

bool IsNumber(string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if ((input[i] < '0' || input[i] > '9') && input[0] != '-')
		{
			return false;
		}
	}

	return true;
}

void HandleWrongInput()
{
	cout << "wrong input!";
	exit(1);
}

int main()
{
	int n, k, i = 0;
	string inputFileName, outputFileName, input;
	cin >> n;
	cin >> k;

	if (n < 1 || k < 1)
	{
		HandleWrongInput();
	}

	cin >> inputFileName;
	cin >> outputFileName;

	int* arr = new int[n];

	ifstream inputFile(inputFileName);
	HandleFailFileOpen(inputFile);

	while (!inputFile.eof())
	{
		inputFile >> input;
		if (!IsNumber(input))
		{
			HandleWrongInput();
		}
		arr[i++] = stoi(input);
	}

	if (i != n)
	{
		HandleWrongInput();
	}

	inputFile.close();

	/////////////////////

	ofstream outputFile(outputFileName);
	HandleFailFileOpen(outputFile);

	for (int i = 0; i < n; i++)
	{
		outputFile << arr[i] << endl;
	}

	delete[] arr;
	outputFile.close();
}
void GetInput()
{
	int n, s, t;
	cin >> n;
	cin >> s;
	cin >> t;
}

Graph* FindShortestPathFromSToT(Graph graph, int s, int t)
{
	int* dArray = graph.BFS(s);
	int n = graph.GetAmountOfVertex();

	for (int i = 0; i < n; i++)
	{
		node* current = graph.GetAdjList(i)->GetHead();
		while (current!=nullptr)
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