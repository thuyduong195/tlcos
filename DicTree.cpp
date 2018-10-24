#include <bits/stdc++.h>
#include "DicTree.h"
using namespace std;
int main()
{
	DicTree a;
	a.Add("hello");
	a.Add("Bye");
	cout<<a.Search("Bye")<<endl;
	cout<<a.Search("bye")<<endl;

	return 0;
}