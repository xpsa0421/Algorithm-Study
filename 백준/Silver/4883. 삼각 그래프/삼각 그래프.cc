#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int nums[100000][3];
int dp[100000][3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	while (true)
	{
		// Input
		int n; cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < 3; j++)
				cin >> nums[i][j];

		// Solve - DP
		dp[0][0] = 0;
		dp[0][1] = nums[0][1];
		dp[0][2] = nums[0][1] + nums[0][2];
		dp[1][0] = nums[0][1] + nums[1][0];
		dp[1][1] = min(dp[1][0], min(dp[0][1], dp[0][2])) + nums[1][1];
		dp[1][2] = min(dp[1][1], min(dp[0][1], dp[0][2])) + nums[1][2];

		for (int i = 2; i < n; i++)
		{
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + nums[i][0];
			dp[i][1] = min(dp[i][0], min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]))) + nums[i][1];
			dp[i][2] = min(dp[i][1], min(dp[i - 1][1], dp[i - 1][2])) + nums[i][2];
		}

		// Output
		cout << t++ << ". " << dp[n - 1][1] << '\n';
	}
}
