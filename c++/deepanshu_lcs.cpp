#include <bits/stdc++.h>
  
int max(long long int a,long long int b);
  

int lcs(char* X, char* Y, long long int m,long long int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
        return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
}
  

int max(long long int a,long long int b)
{
    return (a > b) ? a : b;
}
  

int main()
{
    char X[] = "Deepanshu code";
    char Y[] = "Bansal ";
  
    long long int m = strlen(X);
    long long int n = strlen(Y);
  
    printf("Length of LCS is %d\n", lcs(X, Y, m, n));
  
    return 0;
}