#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,t;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements"<<endl;
    for (int i = 0; i < n; i++)
        cin>>arr[i];
	for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
        }
    }
	cout << "Array after bubble sort: "<<endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}