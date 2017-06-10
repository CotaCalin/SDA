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

	bool isFull();

	void enqueue(int a);
	int dequeue();
	int getFirstEmpty();

	int top();

	Queue() { front = -1; rear = -1; cap = 0; firstEmpty = 0; }
	~Queue(){}



};