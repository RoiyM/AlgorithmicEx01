#pragma once
#include"List.h"

class Queue
{
private:
	List* m_Queue;

public:
	//ctor
	Queue();

	//returns if the queue is empty
	bool IsEmpty();

	//input: data 
	//output: insert the data to the queue
	void Enqueue(int i_DataToAdd);

	//returns the head of the queue and remove it
	int Dequeue();

	//dtor
	~Queue();
};