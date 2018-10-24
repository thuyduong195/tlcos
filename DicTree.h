#include <bits/stdc++.h>
using namespace std;
struct Node
{
	char c;
	Node *child;
	Node *next;
};

class DicTree
{
	private:
		Node *root;

		Node *Add_private(char t,Node *r)
		{
			Node *temp = r ->child;
			if (temp == NULL)
			{
				Node *con = new Node();
				con ->c = t;
				con ->child = NULL;
				con ->next = NULL;
				r ->child = con;
				return con;
			} 

			else
			{
				while (temp ->c != t && temp ->next != NULL)
					temp = temp ->next;
				if (temp ->c == t)
					return temp;
				else
				{
					Node *em = new Node();
					em ->c = t;
					em ->child = NULL;
					em ->next = NULL;
					temp ->next = em;
					return em;
				}
			}
		}

		Node *Search_private(char t,Node *r) const	
		{
			Node *temp = r->child;
			while (temp != NULL)
			{
				if (temp -> c == t)
					return temp;
				temp = temp ->next;
			}
			return 0;
		}

	public:
		DicTree()
		{
			root = new Node();
			root ->child = NULL;
			root ->next = NULL;

		}
		~DicTree(){}
		void Add(const char *t)
		{
			Node *temp = root;
			for (int i = 0;i<strlen(t);i++)
				temp = Add_private(t[i],temp);

			Node *end = new Node();
			end ->c = '~';
			end ->child = NULL;
			end ->next = NULL;

			Node *run = temp ->child;
			if (run == 0)
				temp ->child = end;
			else 
			{
				while (run ->c != '~' && run ->next != NULL)
					run = run->next;

				if (run ->next == NULL)
					run ->next = end;
			}
		}

		bool Search(const char *t) const
		{
			Node *temp = root;
			for (int i = 0;i<strlen(t);i++)
			{
				temp = Search_private(t[i],temp);
				if (temp == NULL)
					return false;
			}

			Node *run = temp ->child;
			while (run != NULL)
			{
				if (run ->c == '~')
					return true;
				run = run ->next;
			}
			return false;
		}
};