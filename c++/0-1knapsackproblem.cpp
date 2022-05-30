#include <bits/stdc++.h>
using namespace std;

int knapsack(int weight[], int val[], int n, int capacity)
{
    int p[n + 1][capacity + 1];
    for (int i = 0; i < n + 1; i++)
        p[i][0] = 0;
    for (int j = 0; j < capacity + 1; j++)
        p[0][j] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < capacity + 1; j++)
        {
            if (weight[i - 1] <= j)
            {
                p[i][j] = max(val[i - 1] + p[i - 1][j - weight[i - 1]], p[i - 1][j]);
            }
            else if (weight[i - 1] > j)
            {
                p[i][j] = p[i - 1][j];
            }
        }
    }
    return p[n][capacity];
}

int main()
{
    int weight[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int capacity = 7;
    cout << knapsack(weight, val, 4, capacity);

    return 0;
}