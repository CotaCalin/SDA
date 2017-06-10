#include "stack.h"

bool Stack::isEmpty()
{
	if (head == nullptr)
		return true;
	return false;
}

void Stack::push(int a)
{
	Node* n = new Node;
	n->info = a;

	if (head != nullptr)
		n->next = head;

	head = n;
}

int Stack::top()
{
	if (head != nullptr)
		return head->info;
	else
		throw 1;
}

int Stack::pop()
{
	if (head == nullptr)
		throw 1;

	int e = head->info;

	Node* aux;
	aux = head;
	head = head->next;
	delete aux;

	return e;
}
