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


void KMP(string text, string pattern)
{
    int m = text.length();
    int n = pattern.length();

  
    if (n == 0)
    {
        cout << "The pattern occurs with shift 0";
        return;
    }
    if (m < n)
    {
        cout << "Pattern not found";
        return;
    }

    int next[n + 1];

    for (int i = 0; i < n + 1; i++) {
        next[i] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        int j = next[i + 1];

        while (j > 0 && pattern[j] != pattern[i]) {
            j = next[j];
        }

        if (j > 0 || pattern[j] == pattern[i]) {
            next[i + 1] = j + 1;
        }
    }

    for (int i = 0, j = 0; i < m; i++)
    {
        if (text[i] == pattern[j])
        {
            if (++j == n) {
                cout << "The pattern occurs with shift " << i - j + 1 << endl;
            }
        }
        else if (j > 0)
        {
            j = next[j];
            i--;  
        }
    }
}


int main()
{
    string text ;
    string pattern;
    cout<<"Enter the text ";
    cin>>text;
    cout<<"Enter the pattern ";
    cin>>pattern;

    KMP(text, pattern);

    return 0;
}
