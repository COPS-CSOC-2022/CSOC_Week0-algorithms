//Name - Ashish Kumar
//Roll no - 21095027 


#include <bits/stdc++.h>
using namespace std;


int k_sack(int W, int wt[], int val[], int n)
{
    int i, w;
      vector<vector<int>> K(n + 1, vector<int>(W + 1));
 
    for(i = 0; i <= n; i++){
        for(w = 0; w <= W; w++){
            if(i == 0 || w == 0){
               K[i][w] = 0;
            }else if (wt[i - 1] <= w){
                K[i][w] = fmax(val[i - 1] +
                                K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]);
            }else{
                K[i][w] = K[i - 1][w];
            }
                
        }
    }

    return K[n][W];
}



int main(){
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

  int n;
  cout<<"Enter number of items\n";
  cin>>n;

  int wt[n],val[n];
  cout<<"Enter value of items\n";

  for(int i = 0;i<n;i++){
      cin>>val[i];
  }

  cout<<"Enter respective weights of previous items\n";

  for(int i = 0;i<n;i++){
      cin>>wt[i];
  }

  int lim;
  cout<<"Enter the capacity\n";
  cin>> lim;

  int ans = k_sack(lim,wt,val,n);
  cout<<ans<<endl;



}