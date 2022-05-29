#include<bits/stdc++.h>
using namespace std  ;

int knap( int wt[] , int profit[] , int W , int n)
{
    vector< vector<int> > ans( n+1 , vector<int>(W+1) );

    for( int i = 0 ; i <= n ; i++)
    {
        for( int j = 0 ; j<= W ; j++)
        {
            if( i == 0 || j == 0)
            {
                ans[i][j] = 0 ;
            }
            else if( wt[i-1] <= j )
            {
                ans[i][j] = max( profit[i-1] + ans[i-1][j - wt[i-1]] , ans[i-1][j]);
            }
            else
            {
                ans[i][j] = ans[i-1][j] ;
            }
        }
    }
    return ans[n][W];
}

int main()
{
    int val[] ={3,4,6,5};
    int profit[] = {20,30,10,40} ;
    int W = 8 ;
    int size = sizeof(val)/sizeof(val[0]);

    cout << knap( val , profit , W , size );
    return 0 ;
}