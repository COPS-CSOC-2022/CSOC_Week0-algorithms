#include <bits/stdc++.h>
#define N 4
using namespace std;
void solutions(int chessBoard[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << " " << chessBoard[i][j] << " ";
        printf("\n");
    }
}
bool queenPosition(int chessBoard[N][N], int row, int coloumn)
{
    int i, j;

    for (i = 0; i < coloumn; i++)
        if (chessBoard[row][i])
            return false;

    for (i = row, j = coloumn; i >= 0 && j >= 0; i--, j--)
        if (chessBoard[i][j])
            return false;
 
    for (i = row, j = coloumn; j >= 0 && i < N; i++, j--)
        if (chessBoard[i][j])
            return false;
 
    return true;
}
bool solveNQueen(int chessBoard[N][N], int coloumn)
{
    if (coloumn >= N)
        return true;
    for (int i = 0; i < N; i++) {
        if (queenPosition(chessBoard, i, coloumn)) {
            chessBoard[i][coloumn] = 1;
            if (solveNQueen(chessBoard, coloumn + 1))
                return true;
            chessBoard[i][coloumn] = 0;
        }
    }
    return false;
}

bool solveNQByBacktracking()
{
    int chessBoard[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };
 
    if (solveNQueen(chessBoard, 0) == false) {
        cout << "Solution does not exist";
        return false;
    }
 
    solutions(chessBoard);
    return true;
}

int main()
{
    solveNQByBacktracking();
    return 0;
}
 