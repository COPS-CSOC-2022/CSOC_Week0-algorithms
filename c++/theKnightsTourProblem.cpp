#include <bits/stdc++.h>
#define lli long long int
#define endl "\n"

using namespace std;

int getans(int x, int y, int movement, int ans[8][8], int movementX[], int movementY[]);

int checker(int x, int y, int ans[8][8])
{
	return (x >= 0 && x < 8 && y >= 0 && y < 8 && ans[x][y] == -1);
}

void printSolution(int ans[8][8])
{
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++){
			cout << " " << setw(2) << ans[x][y] << " ";
        }
		cout << endl;
	}
}

int solveKT()
{
	int ans[8][8];
	for (int x = 0; x < 8; x++)
    {
		for (int y = 0; y < 8; y++){
            ans[x][y] = -1;
        }
    }
	int movementX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int movementY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	ans[0][0] = 0;

	if (getans(0, 0, 1, ans, movementX, movementY) == 0) {
		cout << "Solution does not exist";
		return 0;
	}
	else{
		printSolution(ans);
        return 1;
    }
}

int getans(int x, int y, int movement, int ans[8][8], int movementX[8], int movementY[8])
{
	int next_x, next_y;
	if (movement == 64)
		return 1;
	for (int i = 0; i < 8; i++) {
		next_x = x + movementX[i];
		next_y = y + movementY[i];
		if (checker(next_x, next_y, ans)) {
			ans[next_x][next_y] = movement;
			if (getans(next_x, next_y, movement + 1, ans, movementX, movementY) == 1){
				return 1;
            }
			else{
				ans[next_x][next_y] = -1;
            }
		}
	}
	return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(__null);
	solveKT();
	return 0;
}