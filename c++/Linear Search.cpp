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

int linearsearch(int Arr[],int num,int p){
	int u=-1;
	for(int o=0;o<num;o++){
		if(Arr[o]==p){
			u=o;
			break;
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
    int x=linearsearch(arr,n,3);
    if(x==-1){
    	cout<<"Element Not Present in the Array"<<endl;
    }
    else{
    	cout<<"Element Present at Index"<<x<<endl;
    }
  	
  		
  		

  	
  
}
    	
 



    
