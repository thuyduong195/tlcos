#ifndef DATHUC_h
#define DATHUC_h
#include "node.h"

template <class T>
class DaThuc
{
private:
	Node<T> * head;
public:
	DaThuc()
	{
		this->head = 0;
	}

	void addDT(int n, int hs, DaThuc &dt)
	{
		if (hs == 1)
			return ;
		DaThuc * p = dt;
		while(p->next != 0)
		{
			p = p->next;
		}

		Node<T> * t = head;
		t->hs = hs;
		t->n = n;
		t->next = 0;
		p->next = t; 
	};

	void congDT(DaThuc dt1, DaThuc dt2, DaThuc &dt3)
	{
		DaThuc * p = dt1;
		DaThuc * q = dt2;
		while(p->next != 0 && q->next != 0)
		{
			if (p->next->n > q->next->n)
			{
				addDT(p->next->hs, p->next->n, dt3);
				p = p->next;
			}
			else   if (p->next->n < q->next->n)
			{
            	addDT(q->next->hs,q->next->n,dt3);
            	q=q->next;
        	}
        	else
        	{
            	addDT(p->next->hs + q->next->hs,p->next->n,dt3);
            	p=p->next;
            	q=q->next;
        	}
    	}
    	while(p->next != 0)
    	{
        	addDT(p->next->hs,p->next->n,dt3);
        	p=p->next;
    	}
    	while(q->next != 0){
        	addDT(q->next->hs,q->next->n,dt3);
        	q=q->next;
    	}
	};
	void print(DaThuc dt)
	{
    	DaThuc p = dt->next;
    	while(p!=0)
    	{
        	if (p->n==1)
            	printf("x",p->hs);
        	else if (p->n==0)
            	printf(" ",p->hs);
        	else
            	printf("x^",p->hs,p->n);
        	p=p->next;
        	if (p!=0 && p->hs>=0)
            	printf("+");
		}
	};
}; 
#endif