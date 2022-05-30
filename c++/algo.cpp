//0-1 knapsack problem
#include <bits/stdc++.h>
 using namespace std;
//to get max of two functions
int max(int a, int b) { 
    if(a>b) return a;
    else return b; 
}
 
// max value that can be put in knapsack of weight W
int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;
 
    // If weight of the nth item is more than
    // Knapsack capacity W, then this item cannot
    // be included in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
 

    else return max(val[n - 1]+ knapSack(W - wt[n - 1],wt, val, n - 1), knapSack(W, wt, val, n - 1));
}
 
// Driver program to test above function
int main()
{
    int val[] = { 20, 50, 80 };
    int wt[] = { 10, 50, 100};
    int W = 80;
    int n = sizeof(val) / sizeof(val[0]);
    cout<<knapSack(W, wt, val, n);
    return 0;
}
