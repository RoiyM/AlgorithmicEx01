#pragma once
#include"List.h"

class Queue
{
private:
	List* m_Queue;

public:
	Queue();
	bool IsEmpty();
	void Enqueue(int i_DataToAdd);
	int Dequeue();
	~Queue();
};