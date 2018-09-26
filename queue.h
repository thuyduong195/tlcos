#ifndef queue_h
#define queue_h
#include "node.h"


template <class T>
class Queue
{
private:	
	Node<T> *head;
	Node<T> *bottom;

public:
	Queue()
	{
		head = 0;
		bottom = 0;
	};
	void queue(T Value)
	{
		Node<T> *n = new Node<T>;
		n->data = Value;
		n->next = 0;
		if(head == 0)
			head = bottom = n;
		else
		{
			bottom->next = n;
			bottom = n;	
		}

	};
	T DeQueue()
	{
		T t = head->data;
		Node<T> *q = head;
		head = head->next;
		delete q;
		return t;
	};
	bool IsEmpty() const
	{
		return head == 0;
	};
};
#endif
