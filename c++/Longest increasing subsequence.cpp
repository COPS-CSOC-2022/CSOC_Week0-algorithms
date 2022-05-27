//Author - Puneet Awasthi (21065086)
#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define INF 1e18
#define fo(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define Fo(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
typedef pair<int, int> pi;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long int> vlli;
#define pb push_back
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);

int lis(int arr[],int n){
	vi v;
	v.pb(arr[0]);
	for (int i=1;i<n;i++){
		if(arr[i]>v.back()){
			v.pb(arr[i]);
		}
		else {
			int id = lower_bound(v.begin(),v.end(),arr[i])-v.begin();
			v[id] = arr[i];
		}
	}
	return v.size();
}

int main(){
	IOS
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vi v;
	v.pb(arr[0]);
	for (int i=1;i<n;i++){
		if(arr[i]>v.back()){
			v.pb(arr[i]);
		}
		else {
			int id = lower_bound(v.begin(),v.end(),arr[i])-v.begin();
			v[id] = arr[i];
		}
	}
	cout<<v.size();
}




