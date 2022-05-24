#include <bits/stdc++.h>
using namespace std;
const int  N=25e2+100;
vector<int>a(N);
int dp[N];

int LIS(vector<int> &a, int i){
    if(dp[i]!= -1){
        return dp[i];
    }
    int num=1;
    for(int j=0;j<i;j++){
        if(a[i]>a[j]){
            num=max(num, LIS(a,j)+1);
        }
    }
    return dp[i]=num;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    int ans=0;
    for (int i = 0; i < n; ++i)
    {
        ans=max(ans,LIS(a,i));
    }
    cout<<"Length of LIS is:"<<ans;
}

/* Sample Cases:
INPUT:
8
10 22 9 33 21 50 41 60
OUTPUT:
Length of LIS is:5

INPUT:
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
OUTPUT:
Length of LIS is:6

*/
