#include "Queue.h"

Queue::Queue()
{
	m_Queue = new List();
}
bool Queue::IsEmpty()
{
	return m_Queue->IsEmpty();
}

void Queue::Enqueue(int i_DataToAdd)
{
	m_Queue->AddToHead(i_DataToAdd);
}
int Queue::Dequeue()
{
	if (m_Queue->IsEmpty())
	{
		throw "the Queue is empty!";
	}

	return m_Queue->DeleteTail();
}

Queue::~Queue()
{
	delete m_Queue;
}