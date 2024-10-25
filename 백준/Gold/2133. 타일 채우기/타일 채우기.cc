#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// Input
	int n; cin >> n;

	// Solve - DP
	if (n % 2 == 1)
	{
		cout << 0;
		return 0;
	}
	
	int dp[31] = {1};
	dp[2] = 3;
	for (int i = 4; i <= n; i+=2)
	{
		dp[i] = dp[i - 2] * dp[2];
		for (int j = 4; j <= i; j++)
		{
			dp[i] += dp[i - j] * 2;
		}
	}

	// Output
	cout << dp[n];
}
