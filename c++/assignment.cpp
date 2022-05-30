#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define endl '\n'
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
#define p(x) setprecision(x) 
#define pi 3.1415926536
#define ll long long
#define N 6
using namespace std;
int maze[N][N]  =  {
   {1, 0, 1, 1, 1,1},
   {1, 1, 0, 0, 0,1},
   {0, 1, 0, 0, 0,1},
   {1, 1, 1, 1, 1,1},
   {0, 0, 0, 1, 1,1},
   {0, 0, 0, 1, 0,1}
};

int ans[N][N];         
void () {
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++)
         cout << ans[i][j] << " ";
      cout << endl;
   }
}

bool isvalid(int x, int y) {      
   if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
      return true;
   return false;
}

bool solveMaze(int x, int y) {
   if(x == N-1 && y == N-1) {     
      ans[x][y] = 1;
      return true;
   }

   if(isvalid(x, y) == true) {    
      ans[x][y] = 1; 
      if (solveMaze(x+1, y) == true)       
         return true;
      if (solveMaze(x, y+1) == true)         
         return true;
      ans[x][y] = 0;         
      return false;
   }  
   return false;
}

bool findSolution() {
   if(solveMaze(0, 0) == false) {
      cout << "There is no path";
      return false;
   }
   ();
   return true;
}
int main() {
   Solution();
}
//output
// 1 0 0 0 0 0 
// 1 1 0 0 0 0 
// 0 1 0 0 0 0 
// 0 1 1 1 0 0 
// 0 0 0 1 1 1 
// 0 0 0 0 0 1