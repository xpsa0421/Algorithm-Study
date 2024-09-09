#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(m, 0));
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, 1000)));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	// First row
	for (int j = 0; j < m; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			dp[0][j][k] = map[0][j];
		}
	}

	// Remaining rows
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 왼쪽 대각선에서 오는 경우
			if (j != 0) 
				dp[i][j][0] = map[i][j] + min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]);

			// 위에서 오는 경우
			dp[i][j][1] = map[i][j] + min(dp[i - 1][j][0], dp[i - 1][j][2]);

			// 오른쪽 대각선에서 오는 경우
			if (j != m - 1) 
				dp[i][j][2] = map[i][j] + min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]);
		}
	}

	// Retrieve answer
	int ans = 1000;
	for (int j = 0; j < m; j++)
	{
		ans = min(ans, min(dp[n - 1][j][0], min(dp[n - 1][j][1], dp[n - 1][j][2])));
	}
	cout << ans;
}