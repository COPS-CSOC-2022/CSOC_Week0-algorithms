
//Returns all the solution for a particular value of n
//The solution is in the form of permutations from 1 to n where the ith value
//the permutation shows the row numbers in a queen is placed for ith column

//Sample Input 5
//Sample Output:
//[1 3 5 2 4 ] [1 4 2 5 3 ] [2 4 1 3 5 ] [2 5 3 1 4 ] [3 1 4 2 5 ] [3 5 2 4 1 ] [4 1 3 5 2 ] [4 2 5 3 1 ] [5 2 4 1 3 ] [5 3 1 4 2 ]   
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   vector<vector<int>>ans;
   bool issafe(vector<vector<int>> board, int row, int col)
{   
   int n = board.size();
   for(int i = 0; i<col; ++i)
   {
   	//checking previous columns
       if(board[row][i])
       return false;
       
   }
   //checking diagonals
   for(int i=row, j=col; i>=0 && j>=0; --i, --j)
   {
       if(board[i][j])
       return false;
   }
   
   for(int i=row, j=col; i<n && j>=0; ++i, --j)
   {
       if(board[i][j])
       return false;
   }
   
   return true;
}


bool solve(vector<vector<int>> &board, int col)
{
   int n = board.size();
   if(col == n)
   {
       vector<int> v;
       //checking if all the queens placed
       for(int i=0; i<n; ++i)
       {
           for(int j=0; j<n; ++j)
           {   if(board[i][j] == 1)
               v.push_back(j+1);
           }
       }
       
       ans.push_back(v);
       return true;
   }
   bool res = false;
   //checking another solution by backtracking
   for(int i=0; i<n; ++i)
   {
       if(issafe(board, i, col))
       {
           board[i][col] = 1;
           
          res = (solve(board,col+1)) || res ;
          
           
           board[i][col] = 0;
       }
       
   }
   
   return res;
}


   vector<vector<int>> nQueen(int n) {
       vector<vector<int>> board(n, vector<int>(n,0));
       //no answer
       if(solve(board, 0) == false)
       return {};
       //answer exists 
       sort(ans.begin(), ans.end());
       return ans;
       
   }
};
    



int main(){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    return 0;
}  
