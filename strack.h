#ifndef strack_h
#define stack_h
#include "node.h"

template <class T>  
class Stack
{
private:
	Node<T> *top;

public:
	Stack()
	{
		top = 0;
	};
	void Push(T Value)
	{
		Node<T> *n = new Node<T>;
		n->data = Value;
		n->next = top;
		top = n;
	};
	T pop()
	{
		T t = top->data;
		Node<T> *q = top;
		top = top->next;
		delete q;
		return t;
	};
	bool IsEmpty() const
	{
		return top == 0;
	};
};
#endif
