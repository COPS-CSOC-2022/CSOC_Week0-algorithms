#include <bits/stdc++.h>
using namespace std;


int weight[] = {10, 20, 30};
int value[] = {60, 100, 120};

int knapsack(int weight_left, int index) {
    if (index == -1 or weight_left < weight[index]) return 0;
    int a = knapsack(weight_left, index-1);
    int b = knapsack(weight_left - weight[index], index-1) + value[index];
    return max(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int bag_weight = 50;
    int items = 3;
    cout << knapsack(bag_weight, items);
}
