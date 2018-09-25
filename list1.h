#ifndef LIST_h
#define LIST_h
#include <iostream>
using namespace std;
#include "Node.h"
template <typename T>
class List
{
	Node<T> *head;
	Node<T> * tail;
	int size;
public:
	List(){
		this -> head = NULL;
		this -> tail = NULL;	
	}
	//front
	void pushFront(T data)
	{
		Node<T> * n = new Node<T>(data);
		if (isEmpty())
		{
			this -> head = n;
			this -> tail = n;
		}
		else
		{
			n -> next = head;
			this -> head = n;
		}
		this -> size++;
	};

	bool popFront()
	{
		if (isEmpty())
		{
			return false;
		}else
		{
			if (this -> head == this -> tail)
			{
				delete this -> head;
				this -> head = NULL;
				this -> tail = NULL;
			}
			else
			{
				Node<T> *temp = head;
				head =  head -> next;
				delete temp;
			}
			this -> size--;
			return true;
		}
	};

	T topFront() const
	{
		return this -> head -> value;
	};

	//back
	void pushBack(T data)
	{
		Node<T> * n = new Node<T>(data);
		if (isEmpty())
		{
			this -> head = n;
			this -> tail = n;
		}
		else
		{
			this -> tail -> next = n;
			this -> tail = n;
		}
		this -> size++;
	};
	T topBack() const
	{
		return this -> tail -> value;
	};

	bool popBack()
	{
		if (isEmpty())
		{
			return false;
		}
		else
		{
			if (this -> head == this -> tail)
			{
				delete this -> head;
				this -> head = NULL;
				this -> tail = NULL;
			}
			else
			{
				Node<T> *temp = this -> head;
				while(temp-> next -> next != NULL)
				{
					temp = temp -> next;
				}
				this -> tail = temp;
				delete temp->next;
				temp->next = NULL;
			}
			this -> size --;
			return true;
		};
		
	}


	int Size()const
	{
		return this -> size;
	};

	T max()const
	{
		T max = head->next;
		Node <T>*p = head->next;
		while(p != 0)
		{
			if(max > p->data)
			{
				max = p->data;
			}
		p = p->next;	
		}
		return max;
	};

	T min()const
	{
		T min = head->next;
		Node <T>*p = head->next;
		while(p != 0)
		{
			if(min < p->data)
			{
				min = p->data;
			}
		p = p->next;	
		}
		return min;
	};
	bool isEmpty()const
	{
		return this -> head == NULL;
	};
	void printAll()const
	{
		Node<T> * temp = head;
		while(temp)
		{	
			cout<<temp -> value<<" ";
			temp = temp -> next;
		}
		cout<<endl;
	};
	void Change(int pos, T value)
	{
		if(pos == 1)
		{
			Node<T> *q = head;
			q->data = value;
		}
		else
		{
			Node<T> *p = head;
			for(int i=1; i<pos-1; i++)
				p = p->next;
			p->next->data = value;
		}
	};
	void DeleteFirst() 
	{
		Node <T> *temp = new Node<T>;	
		temp = top;
		top = temp ->next;
		temp = 0;
		delete temp;
	
	};

	void DeleteEnd() // xóa phần tử cuối trong danh sách liên kết
	{
		Node <T> *temp = new Node<T>;
		Node <T> *current = new Node<T>;
		temp = top;
		while(temp -> next != 0)
		{
			current = temp;
			temp = temp ->next;
		}
		current -> next = 0;
		tail = current;
		delete current->next;
	};
	void Reverse()
	{
		Node <T>*t = 0;
		Node <T>*p = head;
		while(p != 0)
		{
			Node <T>* n = new Node<T>;
			n->data = p->data;
			n->next = t;
			t = n;
			Node<T>*q = 0;
			p = p->next;
			delete q;
		}
		head = t;
	};
	
	
};
#endif