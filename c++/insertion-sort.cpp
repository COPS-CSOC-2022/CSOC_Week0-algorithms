#include<bits/stdc++.h>
using namespace std;

// Sorting Function
void InsSort(int ar[], int n)
{
	int k,j;
	for (int i=1;i<n;i++)
	{
		k=ar[i];
		j=i-1;
		while(j>=0 && ar[j]>k)
		{
			ar[j+1]=ar[j];
			j=j-1;
		}
		ar[j+1]=k;
	}
}

// Sorted Array Print Function
void PrintArray(int ar[], int n)
{
	for (int i=0;i<n;i++)
		cout<<ar[i]<<" ";
	cout<<endl;
}

// Main Function
int main()
{
	int ar[]={ 19, 10, 8, 17, 9 };
	int n=sizeof(ar)/sizeof(ar[0]);
	InsSort(ar, n);
	PrintArray(ar, n);
	return 0;
}
