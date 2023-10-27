#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int t = 0;
	cin >> t;

	while (t--)
	{
		int n = 0;
		cin >> n;
		
		vector<vector<int>> scores(2, vector<int>(n + 1));
		vector<vector<int>> dp(2, vector<int>(n + 1, 0));

		for (int r = 0; r < 2; r++)
		{
			for (int c = 1; c <= n; c++)
			{
				cin >> scores[r][c];
			}
		}
		dp[0][1] = scores[0][1];
		dp[1][1] = scores[1][1];
		for (int c = 2; c <= n; c++)
		{
			dp[0][c] = scores[0][c] + max(dp[1][c - 1], dp[1][c - 2]);
			dp[1][c] = scores[1][c] + max(dp[0][c - 1], dp[0][c - 2]);
		}

		cout << (dp[0][n] > dp[1][n] ? dp[0][n] : dp[1][n]) << "\n";
	}
}

