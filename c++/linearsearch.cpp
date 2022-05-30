//Algorithm to find the required element in a given array
#include <iostream>

using namespace std;
int elem(int n, int arr[]);

int main()
{
    int n;
    int arr[] = {1, 3, 4, 7, 8};
    cout<<"Enter the element to be found: "<<endl;
    cin>>n;
    int res = elem(n, arr);
    if(res == -1) cout<<"Element is not found"<<endl;
    else cout<<"Element is found at position"<<" "<<n<<endl;
    return 0;
}

int elem(int n, int arr[])
{
    for(int i = 0; i < 5; i++)
    {
        if(arr[i] == n) return i;
    }
    return -1;
}
