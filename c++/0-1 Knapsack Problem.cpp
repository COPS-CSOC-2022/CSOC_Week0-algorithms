#include <bits/stdc++.h>
using namespace std;


int Knapsack(int W, int weight[], int value[], int item)
{
    int i, w;
      vector<vector<int>> Knap(item + 1, vector<int>(W + 1));
 
    for(i = 0; i <= item; i++){
        for(w = 0; w <= W; w++){
            if(i == 0 || w == 0)
            {
               Knap[i][w] = 0;
            }
            else if (weight[i - 1] <= w)
            {
                Knap[i][w] = fmax(value[i - 1] +Knap[i - 1][w - weight[i - 1]],Knap[i - 1][w]);
            }
            else{
                Knap[i][w] = Knap[i - 1][w];
            }
                
        }
    }

    return Knap[item][W];
}



int main()
{

  int item;
  cout<<"Enter the Number of items\n";
  cin>>item;

  int weight[item],value[item];
  cout<<"Enter the values of items\n";

  for(int i = 0;i<item;i++){
      cin>>value[i];
  }

  cout<<"Enter the respective weights of previous items\n";

  for(int i = 0;i<item;i++){
      cin>>weight[i];
  }

  int capacity;
  cout<<"Enter the capacity\n";
  cin>> capacity;

  int knapSackValue = Knapsack(capacity,weight,value,item);
  cout<<"The Maximum total value in the knapsack is : \n";
  cout<<knapSackValue<<endl;


}