#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
const int N =100001;
const int P =1e9+7;
const ll inf=LLONG_MAX;
#define pb                     push_back
#define all(x)              x.begin(), x.end()
#define ff                     first
#define ss                     second
#define cnu                    continue

int Edis(string s1, string s2, int x, int y, vector<vector<int>> &dp){       
  if(x==0)    return y;
         
  if(y==0)    return x;


  if(dp[x][y]!=-1)    return dp[x][y];

         
  if(s1[x-1]==s2[y-1]){          
    if(dp[x-1][y-1]==-1){              
      return dp[x][y] = Edis(s1, s2, x-1, y-1, dp);          
    }       
    else
      return dp[x][y] = dp[x-1][y-1];  
  }
       
  else{          
    int y1, y2, y3;        
     
    if(dp[x-1][y]!=-1){   
      y1 = dp[x-1][y];     
    }          
    else{  
      y1 = Edis(s1, s2, x-1, y, dp);     
    }           
             
    if(dp[x][y-1]!=-1){               
      y2 = dp[x][y-1];           
    }           
    else{   
      y2 = Edis(s1, s2, x, y-1, dp);     
    }                                  
    
    if(dp[x-1][y-1]!=-1){   
      y3 = dp[x-1][y-1];     
    }  
    else{  
      y3 = Edis(s1, s2, x-1, y-1, dp);      
    }    
    return dp[x][y] = 1+min(y1, min(y2, y3));       
  }
   
}


int main() {
    IOS;
   
 

   string a;
   string b;
   cin>>a>>b;

   int x = a.length();
   int y = b.length();   
  vector<vector<int>> dp(x+1, vector<int>(y+1, -1));

  cout<<Edis(a, b, x, y, dp);
   
return 0;
   } 

/*
SAMPLE CASES

 INPUT:
 bingo table

 OUTPUT:
 5  
 */