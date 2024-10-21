#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
 
// 01:37
int n;
int map[16][16];
int dp[16][16][3];
int ans = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	dp[0][1][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (i == 1 && j == 1) continue;
			if (map[i][j] == 1) continue;

			// 가로 (가로, 대각선 -> 가로)
			dp[i][j][0] += dp[i][j - 1][0];
			dp[i][j][0] += dp[i][j - 1][2];

			if (i != 0)
			{
				// 세로 (세로, 대각선 -> 세로)
				dp[i][j][1] += dp[i - 1][j][1];
				dp[i][j][1] += dp[i - 1][j][2];
				
				// 대각선
				if (map[i - 1][j] == 0 && map[i][j - 1] == 0)
				{
					dp[i][j][2] += dp[i - 1][j - 1][0];
					dp[i][j][2] += dp[i - 1][j - 1][1];
					dp[i][j][2] += dp[i - 1][j - 1][2];
				}
			}
		}
	}

	ans = dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
	cout << ans;
}
