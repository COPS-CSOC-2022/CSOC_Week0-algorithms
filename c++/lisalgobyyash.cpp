#include<bits/stdc++.h>
#define ll long long
#define di(a) ll a;cin>>a;
#define dia di(a)
#define dix di(x)
#define diT di(T)
#define din di(n)
#define V vector<ll>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); //for competitve programming
using namespace std;
const int N =1e5+10;

//using dynamic programming to find Longest Increasing Subsequence (LIS)

ll dp[N];

ll lisfunc(ll i,V &v){
    if(dp[i]!=-1) return dp[i];
    ll ans=1;
    for (int j = 0; j < i; ++j)
    {
        if(v[j]<v[i]){
            ans=max(ans,lisfunc(j,v)+1);
        }
    }
    return dp[i]=ans;
}
 
int main(){
    fastio;
    
    //T -->Test cases.
    ll T=1;
    cin>>T;
    while(T--){
        memset(dp,-1,sizeof(dp));
        din;
        V v(N);
        for (int i = 0; i < n; ++i)
        {
            cin>>v[i];
        }
        ll res=1;
        for (int i = 0; i < n; ++i)
        {
            res=max(res,lisfunc(i,v));
        }
        cout<<res<<endl;
        
        
 
    }
    return 0;
}

// Sample Test Case:-
// 1
// 8
// 10 9 2 5 3 7 101 18  Ans-->4
