#pragma once

class Node2
{
public:
	int info;
	int next;
	int prev;
	
	Node2() 
	{
		info = 0;
		next = -1;
		prev = -1;
	}

};

class Queue
{
public:
	Node2 nodes[52];
	int front;
	int rear;
	int cap;
	int firstEmpty;

	bool isEmpty();
	/*
	Returns true if the queue is empty
	Returns false if the queeu is not empty
	*/

	bool isFull();
	/*
	Returns true if the queue is full
	Returns false if the queue is not full
	*/

	void enqueue(int a);
	/*
	Adds a to the rear of the queue.
	*/
	int dequeue();
	/*
	Returns and deletes the element from the front if the queue
	*/
	int getFirstEmpty();
	/*
	Returns the first free position from the list
	*/

	int top();
	/*
	Returns the element from the front if the queue
	*/

	Queue() { front = -1; rear = -1; cap = 0; firstEmpty = 0; }
	~Queue(){}



};
