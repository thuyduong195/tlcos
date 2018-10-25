#include <iostream>
using namespace std;
#include "dictionarytree.h"

int main()
{
	DicTree *a;
	a.Add("Girl");
	a.Add("New");
	a.Add("Generation");
	cout<<Tra("Girl")<<endl;
	cout<<Tra("Boy")<<endl;
	return 0;
}
