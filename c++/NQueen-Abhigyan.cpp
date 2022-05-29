#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl "\n"
#define pb push_back
#define PI 3.141592653589
#define N 4
const ll MOD = 1e9 + 7;

void printSolution(ll board[N][N])
{
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
            cout << " " << board[i][j] << " ";
        printf("\n");
    }
}

bool isSafe(ll board[N][N], ll row, ll col)
{
    ll i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
    return true;
}

bool solveNQUtil(ll board[N][N], ll col)
{
    if (col >= N)
        return true;
    for (ll i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

bool solveNQ()
{
    ll board[N][N] = {{0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0}};

    if (solveNQUtil(board, 0) == false)
    {
        cout << "Solution does not exist";
        return false;
    }

    printSolution(board);
    return true;
}

int32_t main()
{
    solveNQ();
    return 0;
}