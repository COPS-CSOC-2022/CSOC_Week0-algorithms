#include<bits/stdc++.h>
#define ll long long
#define p(x) setprecision(x) 
#define pi 3.1415926536
using namespace std;
bool safemove(ll** u,ll n,ll x,ll y){
if(x<n && y<n && u[x][y]==1){
	return true;
}
else{
	return false;
}
}
bool solve(ll** u,ll** v,ll n,ll x,ll y){
 if(x+1==n && y+1==n){
	v[x][y]=1;
	return true;
}
else if(safemove(u,n,x,y)){
	v[x][y]=1;
	if(solve(u,v,n,x+1,y)){
		return true;
	}
	if(solve(u,v,n,x,y+1)){
		return true;
	}
	
		v[x][y]=0;
		return false;
}
else{
	return false;
}
}
int main(){
ll n;
cin>>n;
ll** given=new ll*[n];
for (ll i = 0; i < n; ++i)
{
	given[i]=new ll[n];
}
ll** ans=new ll*[n];
for (ll i = 0; i < n; ++i)
{
	ans[i]=new ll[n];
}
for (ll i = 0; i < n; ++i)
{
	for (ll j = 0; j <n; ++j)
	{
		cin>>given[i][j];
	}
}
for (ll i = 0; i < n; ++i)
{
	for (ll j = 0; j <n; ++j)
	{
		ans[i][j]=0;
	}
}
if(solve(given,ans,n,0,0)){
	for (ll i = 0; i < n; ++i)
{
	for (ll j = 0; j <n; ++j)
	{
		
		cout<<ans[i][j]<<" ";
	}
	cout<<"\n";
}
}
else{
	cout<<"No Path Exists"<<"\n";
}
return 0;
}


/*
Sample Input 1
5
1 1 0 0 1
1 1 0 1 1
1 0 1 0 1
1 1 0 0 0
0 1 1 1 1
Output 1
1 0 0 0 0 
1 0 0 0 0
1 0 0 0 0
1 1 0 0 0
0 1 1 1 1

Sample Input 2
4
1 0 1 1
0 1 1 1
1 1 1 1
0 0 1 1
Output 2
No Path Exists
*/
