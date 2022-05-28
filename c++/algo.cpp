#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define isodd % 2 == 1
#define iseven % 2 == 0
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define back(v) v.rbegin(), v.rend()
#define vi vector<ll>
using namespace std;

int main()
{
    // IOS;
    ll n;
    cout<<"Enter the size of the array:"; 
    cin >> n;
    ll a[n];
    cout << "Enter the elements of the array\n";
    rep(i, n)
    {
        cin >> a[i];
    }
    ll sum;
    cout << "Enter the sum to find out whetherit is the subset sum of the array";
    cin >> sum;
    bool t[n + 1][sum + 1];
    rep(i,sum+1){
        t[0][i] =false;
    }
    rep(i,n+1){
        t[i][0] =true;
    }
    for (ll i = 1; i < n + 1; i++)
    {
        for (ll j = 1; j < sum + 1; j++)
        {
            if (j < a[i - 1])
                t[i][j] = t[i - 1][j];
            if (j >= a[i - 1])
                t[i][j] = t[i - 1][j] || t[i - 1][j - a[i - 1]];
        }
    }
    t[n][sum]?cout<<"Yes the subset sum exist\n":cout<<"No the subset sum does not exist\n";
    return 0;
}