//  Rat in a Maze problem algo

#include <bits/stdc++.h>
using namespace std;
#define N 4

void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << " " << sol[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int maze[N][N], int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool solvearrtill(int arr[N][N], int x, int y, int solution[N][N])
{
    if (x == N - 1 && y == N - 1 && arr[x][y] == 1)
    {
        solution[x][y] = 1;
        return true;
    }
    if (isSafe(arr, x, y) == true)
    {
        if (solution[x][y] == 1)
        {
            return false;
        }
        solution[x][y] = 1;
        if (solvearrtill(arr, x + 1, y, solution) == true)
        {
            return true;
        }
        if (solvearrtill(arr, x, y + 1, solution) == true)
        {
            return true;
        }
        solution[x][y] = 0;
        return false;
    }
    return false;
}

bool solvearr(int arr[N][N])
{
    int solution[N][N] = {{0, 0, 0, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0}};
    if (solvearrtill(arr, 0, 0, solution) == false)
    {
        cout << "Solution doesn't exist";
        return false;
    }
    printSolution(solution);
    return true;
}

int main()
{
    int arr[N][N] = {{1, 1, 1, 0},
                     {0, 0, 1, 1},
                     {0, 1, 0, 1},
                     {1, 1, 1, 1}};
    solvearr(arr);
    return 0;
}