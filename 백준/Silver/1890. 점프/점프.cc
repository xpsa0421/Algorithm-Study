#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> nums(n, vector<int>(n, 0));
	vector<vector<long long>> dp(n, vector<long long>(n, 0));
	dp[0][0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> nums[i][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (nums[i][j] == 0) continue;

			int move = nums[i][j];
			if (move == 0) continue;

			// Down
			if (i + move < n)
			{
				dp[i + move][j] += dp[i][j];
			}

			// Right
			if (j + move < n)
			{
				dp[i][j + move] += dp[i][j];
			}
		}
	}

	cout << dp[n-1][n-1];
}