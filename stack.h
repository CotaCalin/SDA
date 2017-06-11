#pragma once

class Node
{
public:
	Node()
	{
		next = nullptr;
	}

	Node* next;
	int info;

	~Node(){}
};
class Stack
{
public:
	Node* head;
	Stack()
	{
		head = nullptr;
	}

	bool isEmpty();
	/*
	Returns true if the stack is empty
	Returns false if the stack is not empty
	*/
	void push(int a);
	/*
	Pushes a on top of the stack
	*/
	int top();
	/*
	Returns the element from the top of the stack
	*/
	int pop();
	/*
	Returns and deletes the element from the top of the stack
	*/
	bool isFull() { return false; }
	/*
	Returns False because the list is dynamically allocated and it can't be full
	*/
	~Stack()
	{
		Node* aux;
		Node* aux2;
		aux = head;
	
		while (aux != nullptr)
		{
			aux2 = aux->next;
			delete aux;
			aux = aux2;
		}
	}

};
