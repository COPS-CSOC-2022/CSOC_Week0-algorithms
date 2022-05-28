/* C++ implementation
of LIS problem using Dynamic Programming */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* This returns the length of the longest
increasing subsequence */
ll solve(ll arr[], ll n)
{
    ll mx[n];

    mx[0] = 1;

    /* Find LIS for initial i elements in
       bottom up manner */
    for (ll i = 1; i < n; i++)
    {
        mx[i] = 1;
        for (ll j = 0; j < i; j++)
            if (arr[i] > arr[j] && mx[i] < mx[j] + 1)
                mx[i] = mx[j] + 1;
    }

    // Return maximum value in mx[] as we want the LIS
    ll m = 0;
    for (ll i = 0; i < n; i++)
    {
        m = max(m, mx[i]);
    }
    return m;
}

int main()
{
    ll n;
    cout << "Enter the size of the array\n";
    cin >> n;

    ll arr[n];

    for (ll i = 0; i < n; i++)
    {
        cout << "Enter the " << i << "th element\n";
        cin >> arr[i];
    }
    cout << "Length of Longest Increasing Subsequence  is " << solve(arr, n);

    return 0;
}
