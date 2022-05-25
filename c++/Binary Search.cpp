#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include <cstring>
#include <limits.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(X) X.begin(),X.end()
#define F first
#define S second
using namespace std;

int BinarySearch(int Arr[],int num,int p){
    int u=-1;
	sort(Arr,Arr+num);
    int l=0;
    int r=num-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(Arr[mid]==p){
            return mid;
        }
        else if(Arr[mid]>p){
            r=mid-1;
        }
        else{
            l=mid+1;
        }

    }
	return u;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for(int j=0;j<n;j++){
    	cin>>arr[j];
    }
    int x=BinarySearch(arr,n,3);
    if(x==-1){
    	cout<<"Element Not Present in the Array"<<endl;
    }
    else{
    	cout<<"Element Present at Index"<<x<<endl;
    }
  	
  		
  		

  	
  
}
    	
 



    
