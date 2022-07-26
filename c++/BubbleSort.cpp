#include<iostream>
using namespace std;
int sort(int n,int arr[]){
for(int i=0;i<n-1;i++){
    for(int j=0; j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            int temp;
            temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
            }
    }
    }
    cout<<"{";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ,";
        }
cout<<"}";
    return 0;
}
int main(){
    int n;
    cout<<"enter length of array = ";
    cin>>n;
    int arr[n];
    for(int i;i<n;i++){
        cout<<"Enter the "<<i<<"th element = ";
        cin>>arr[i];
    }
    sort(n,arr);
    return 0;
}