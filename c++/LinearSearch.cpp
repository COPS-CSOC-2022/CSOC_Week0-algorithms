#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements you want to store: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[j]<arr[i]){
                int t = arr[j];
                arr[j] = arr[i];
                arr[i] = t;
            }
        }
    }
    cout<<"Array after sorting is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}