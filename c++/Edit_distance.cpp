#include <bits/stdc++.h>
using namespace std;
int minDis(string name1, string name2, int l, int m,
		vector<vector<int> >& dp)
{

	if (l == 0)
		return m;

	if (m == 0)
		return l;

	
	if (dp[l][m] != -1)
		return dp[l][m];

	
	if (name1[l - 1] == name2[m - 1]) {
		return dp[l][m] = minDis(name1, name2, l - 1, m - 1, dp);
	}
	
	else {
		int insert, del, replace;

		insert = minDis(name1, name2, l, m - 1, dp);
		del = minDis(name1, name2, l - 1, m, dp);
		replace = minDis(name1, name2, l - 1, m - 1, dp);
		return dp[l][m] = 1 + min(insert, min(del, replace));
	}
}


int main()
{

	string FirstStr1 = "Demon";
	string SecStr2 = "Stefen";

	int l = FirstStr1.length(), m = SecStr2.length();
	vector<vector<int> > dp(l + 1, vector<int>(m + 1, -1));

	cout << minDis(FirstStr1, SecStr2, l, m, dp);
	return 0;

}
