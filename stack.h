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

	void push(int a);

	int top();

	int pop();

	bool isFull() { return false; }

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