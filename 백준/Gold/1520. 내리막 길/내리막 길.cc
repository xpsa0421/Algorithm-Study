#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int n, m;
int height[500][500];
int dp[500][500];

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int dfs(int curRow, int curCol)
{
	if (curRow == m - 1 && curCol == n - 1) return 1;
	if (dp[curRow][curCol] != -1) return dp[curRow][curCol];

	dp[curRow][curCol] = 0;
	int curHeight = height[curRow][curCol];
	for (int i = 0; i < 4; i++)
	{
		int nexRow = curRow + dr[i];
		int nexCol = curCol + dc[i];
		if (nexRow < 0 || nexRow == m || nexCol < 0 || nexCol == n) continue;
		if (height[nexRow][nexCol] >= curHeight) continue;

		dp[curRow][curCol] += dfs(nexRow, nexCol);
	}
	return dp[curRow][curCol];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// Input
	cin >> m >> n;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> height[i][j];

	// Solve - DP
	for (int i = 0; i < m; i++) 
		fill(dp[i], dp[i] + n, -1);

	// Output
	cout << dfs(0, 0);
}
