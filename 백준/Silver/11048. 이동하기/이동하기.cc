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

	vector<vector<int>> candies(n, vector<int>(m,0));
	for (int r = 0; r < n; r++) 
		for (int c = 0; c < m; c++) 
			cin >> candies[r][c];

	vector<vector<int>> dp(n, vector<int>(m, 0));
	for (int r = 0; r < n; r++)
		for (int c = 0; c < m; c++)
		{
			if (r > 0) dp[r][c] = max(dp[r][c], dp[r - 1][c]);
			if (c > 0) dp[r][c] = max(dp[r][c], dp[r][c - 1]);
			if (r > 0 && c > 0) dp[r][c] = max(dp[r][c], dp[r - 1][c - 1]);
			dp[r][c] += candies[r][c];
		}

	cout << dp[n - 1][m - 1];
}
