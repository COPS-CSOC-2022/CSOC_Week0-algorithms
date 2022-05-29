#include <iostream>
using namespace std;

bool SubsetSumExist(int set[], int n, int sum){
   
    // Base Case for 0 values
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
 
    if (set[n - 1] > sum)
        return SubsetSumExist(set, n - 1, sum);

    return SubsetSumExist(set, n - 1, sum)
           || SubsetSumExist(set, n - 1, sum - set[n - 1]);
}

int main(){
    int set[] = { 3, 24, 5, 12, 7, 6};
    int sum;
    // What sum are you searching for?
    cin>>sum;
    int n = sizeof(set) / sizeof(set[0]);
    if (SubsetSumExist(set, n, sum) == true)
         cout <<"Yeah there is a subset...!!";
    else
        cout <<"No subset with this sum:'(";
    return 0;
}