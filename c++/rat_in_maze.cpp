
/*  *CSoC'22 Week 0 Second Challenge
    *Rat in a Maze
    *Name: Manash Kumar
    *File: rat_in_a_maze
    *Description: Solving rat in a maze puzzel using backtracking
*/

/*
    *To create a maze of your size and configuration

    1. Change the size of N at line: 30
    
    2. Change the confuguration of maze at line 107 by using 0s
       and 1s at appropriate place
       Here, 0 means blocked element where rat can't go
       and 1 means open element where rat can go

    3. Change the matrix at line 91 and input a valid null
       matrix of size N

    4. Run the code to find possible path!!!
*/


#include<iostream>
using namespace std;

// Given Maze Size (square maze of side N units)
#define N 6
 
// Declaring variables
int x, y;               // Coordinates of Rat
int i, j;               // Index of Matrix

// Validating postion of Rat
bool valid(int maze[N][N], int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;
    else return false;
}
 
// Main function to move Rat
bool solution(int maze[N][N], int x, int y, int sol[N][N])
{
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }
    
    else if (valid(maze, x, y) == true) {

         if (sol[x][y] == 1)
             return false;

         else sol[x][y] = 1;

             // Moving in forward x-direction
             if (solution(maze, x + 1, y, sol) == true)
                return true;

             // Moving in downward y-direction
             if (solution(maze, x, y + 1, sol) == true)
                 return true;

         /* Back tracking previous moves if no forward x-direction
            or downward y-direction move is possible */
         else sol[x][y] = 0;
                return false;
    }
    else return false;
}

// Printing solution Path
void path(int sol[N][N])
{
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            cout<<" "<<sol[i][j]<<" ";
        cout<<endl;
    }
}

/* Will return true if maze can be solved and print
   the path else will return faluse if there is no 
   possible solution*/
   
bool solvingMaze(int maze[N][N])
{
    int sol[N][N] = { { 0, 0, 0, 0, 0, 0 },
                      { 0, 0, 0, 0, 0, 0 },
                      { 0, 0, 0, 0, 0, 0 },
                      { 0, 0, 0, 0, 0, 0 },
                      { 0, 0, 0, 0, 0, 0 },
                      { 0, 0, 0, 0, 0, 0 } };
    if (solution(maze, 0, 0, sol) == false) {
        cout<<"Solution doesn't exist";
        return false;
    }
    else path(sol);
         return true;
}

int main()
{
    int maze[N][N] = { { 1, 1, 0, 0, 1, 0 },
                       { 1, 1, 1, 0, 1, 0 },
                       { 1, 1, 1, 0, 1, 0 },
                       { 0, 1, 1, 0, 1, 0 },
                       { 0, 0, 1, 1, 1, 0 },
                       { 0, 1, 0, 0, 1, 1 } };
    solvingMaze(maze);
    return 0;
}

/* *Sample Input
    1  1  0  0  1  0
    1  1  1  0  1  0
    1  1  1  0  1  0
    0  1  1  0  1  0
    0  0  1  1  1  0
    0  1  0  0  1  1

    *Sample OutPut
    1  0  0  0  0  0 
    1  0  0  0  0  0 
    1  1  0  0  0  0 
    0  1  1  0  0  0 
    0  0  1  1  1  0 
    0  0  0  0  1  1

    *Here Rat start from 0,0 and go upto n,n.
*/