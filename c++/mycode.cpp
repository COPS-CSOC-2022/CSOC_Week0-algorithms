#include <bits/stdc++.h>
using namespace std;


int solmaze(int myMaze[4][4], int a, int b,int sol[4][4]);


void showSol(int sol[4][4])
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			cout<<sol[i][j]<<" ";
		cout<<endl;
	}
}


int safe(int myMaze[4][4], int a, int b)
{
	
	if (a >= 0 && a < 4 &&  b>= 0 && b < 4 && myMaze[a][b] == 1)
		return 1;
	return 0;
}


int solMyMaze(int myMaze[4][4])
{
	int sol[4][4] = { { 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 } };
	if (solmaze(myMaze, 0, 0, sol) == 0) {
		cout<<"There is no Solution";
		return 0;
	}
	showSol(sol);
	return 1;
}


int solmaze(int myMaze[4][4], int a, int b, int sol[4][4])
{
	
	if (a == 3 && b ==  3 && myMaze[a][b] == 1) {
		sol[a][b] = 1;
		return 1;
	}
	
	if (safe(myMaze, a, b) == 1) {
		
		if (sol[a][b] == 1)
			return 0;
		
		sol[a][b] = 1;
		
		if (solmaze(myMaze, a + 1, b, sol) == 1)
			return 1;
		
		if (solmaze(myMaze, a, b + 1, sol) == 1)
			return 1;
		
		sol[a][b] = 0;
		return 0;
	}
	return 0;
}


int main()
{
	int myMaze[4][4] = { { 1, 0, 0, 0 },
					{ 1, 1, 0, 1 },
					{ 0, 1, 0, 0 },
					{ 1, 1, 1, 1 } };
	solMyMaze(myMaze);
	return 0;
}


