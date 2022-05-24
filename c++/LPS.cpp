#include <bits/stdc++.h>
using namespace std;

//Below is the algorithm for the longest palindromic subsequence

//We can use the dynamic programming approach in this case

//Algorithm 
//Let dp[i][j] hold the length of the longest palindromic subsequence

//Case 1: any string of length 1 is always a palindrome => dp[i][i]=1

//Case 2: if the string contains 2 characters then the string would be a palindrome only if both the characters are same
//        if s[i]==s[j] => dp[i][j]=2

//Case 3: if the string contains more than 2 characters there can be two sub-cases:
//sub-case 1: the first and the last character are same
//            if s[i]==s[j] => dp[i][j]=dp[i+1][j-1]+2
//sub-case 2: the first and the last character are different
//            if s[i]!=s[j] => dp[i][j]=max(dp[i+1][j],dp[i][j-1])

//At the end of all these operations dp[0][n-1] will contain the length of the longest palindromic subsequence

int main()
{
    string s;
    cout<<"Enter a string\n";
    getline(cin,s);

    int n = s.size();
    int dp[n][n],i,j,k;

    //Implementation of case 1 algorithm
    for(i=0; i<n; i++)
    {
        dp[i][i]=1;
    }

    for(k=2; k<=n; k++)
    {
        for(i=0; i<=n-k; i++)
        {
            j=i+k-1;
            
            //Implementation of case 2 algorithm
            if(k==2 && s[i]==s[j]) dp[i][j]=2;

            //Implementation of case 3 algorithm sub-case 1
            else if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;

            //Implementation of case 3 algorithm sub-case 2
            else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }

    cout<<"The length of the longest palindromic subsequence is : "<<dp[0][n-1]<<"\n";
}

//Sample Test Case

// Enter a string
// Hello World
// The length of the longest palindromic subsequence is : 5

