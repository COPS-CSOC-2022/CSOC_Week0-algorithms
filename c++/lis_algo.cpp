#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define pb push_back

const int N = 10000000;
int dp[N];
vector<int> v(N);
int lis(int p)
{
	int ans = 1;
	if (dp[p] != -1)
		return dp[p];
	for (int i = 0; i < p; ++i)
	{
		if (v[p] > v[i])
			ans = max(ans, lis(i) + 1);
	}
	return dp[p] = ans;
}

int main()
{
	fastio();
	memset(dp, -1, sizeof(dp));

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	int final = 0;
	for (int i = 0; i < n; ++i)
	{
		final = max(final, lis(i));
	}
	cout << final;
}

// SAMPLE CASES

// INPUT:
// 8
// 10 9 2 5 3 7 101 18

// 4  (OUTPUT)