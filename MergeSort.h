#include <bits/stdc++.h>
using namespace std;

void Merge(int a[],int left,int right)
{
	vector<int> v;
	int i = left;
	int mid = (left + right) /2;
	int j = mid + 1;
	while(i <= mid && j <= right)
	{
		if(a[i] < a[j])
		{
			v.push_back(a[i]);
			i++;
		}
		else
		{
			v.push_back(a[j]);
			j++;
		}
	}
	if (i > mid)
	{
		while(j <= right)
		{
			v.push_back(a[j]);
			j++;
		}
	}
	if (j > right)
	{
		while(i <= mid)
		{
			v.push_back(a[i]);
			i++;
		}
	}

	for (int i = 0 ;i<=right;i++)
		a[left + i] = v[i];

}

void MergeSort(int a[],int left,int right)
{
	if (left < right)
	{
		int mid = (left + right)/2;
		MergeSort(a,left,mid);
		MergeSort(a,mid+1,right);
		Merge(a,left,right);
	}
}

void Input(int a[],int n)
{
	for (int i = 0 ;i<n ; i++)
		cin>>a[i];
}

void Output(int a[],int n)
{
	for (int i = 0 ;i<n ; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}