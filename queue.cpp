#include "queue.h"
#include <iostream>

bool Queue::isEmpty()
{
	if (cap == 0)
		return true;
	return false;
}

bool Queue::isFull()
{
	if(cap == 52)
		return true;
	return false;
}

void Queue::enqueue(int a)
{
	if (cap == 0)
	{
		nodes[firstEmpty].info = a;
		nodes[firstEmpty].prev = firstEmpty;
		front = firstEmpty;
		rear = firstEmpty;
		cap++;
		firstEmpty = getFirstEmpty();
	}
	else
	{
		nodes[firstEmpty].info = a;
		nodes[rear].next = firstEmpty;
		nodes[firstEmpty].prev = rear;
		rear = firstEmpty;
		cap++;
		firstEmpty = getFirstEmpty();
	}

	//std::cout << cap << " " <<firstEmpty << std::endl;
	//std::cout << front << " " << rear << std::endl;

}

int Queue::dequeue()
{
	if (cap == 0)
		throw 2;
	
	int aux = front;

	int e = nodes[front].info;

	front = nodes[front].next;
	cap--;
	nodes[aux].prev = -1;
	nodes[aux].next = -1;

	//std::cout << cap << " " << firstEmpty << std::endl;
	//std::cout << front << " " << rear << std::endl;

	return e;
}

int Queue::getFirstEmpty()
{
	for (int i = 0; i <= 51; i++)
		if (nodes[i].next == -1 && nodes[i].prev == -1)
			return i;
	
}

int Queue::top()
{
	if (cap == 0)
		throw 2;

	return nodes[front].info;
}
