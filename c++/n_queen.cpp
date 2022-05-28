class Solution {
public:

    // Checking if placing a queen at (row, col) is possible or not.

    bool isSafe(int row, int col, vector<string> &temp, int n) {
        int temprow = row;
        int tempcol = col;

        // Checking in upper left diagonal if any queen is already placed.
        while(row>=0 && col>=0) {
            if(temp[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        row = temprow;
        col = tempcol;
        
        // Checking in lower left diagonal if any queen is already placed.
        while(row<n && col>=0) {
            if(temp[row][col] == 'Q') return false;
            row++;
            col--;
        }
        
        row = temprow;
        col = tempcol;

        // Checking in left of that row if any queen is already placed.(<------)
        while(col>=0) {
            if(temp[row][col] == 'Q') return false;
            col--;
        }
        
        return true;
    }
    void search(int col, vector<vector<string>> &ans, vector<string> &temp, int n) {
        if(col == n ) {
            ans.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++) {
            if(isSafe(row, col, temp, n)) {
                temp[row][col] = 'Q';
                search(col+1, ans, temp, n);
                temp[row][col] = '.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {

        // Storing the position of queen placed in board in a 2D vector ans.
        vector<vector<string>> ans;
        vector<string> temp(n);
        string str(n, '.');
        for(int i=0;i<n;i++) temp[i] = str;
        search(0, ans, temp, n);
        return ans;
    }
};