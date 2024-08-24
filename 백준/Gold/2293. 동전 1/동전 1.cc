#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int coins[101];
	for (int i = 0; i < n; i++) cin >> coins[i];

	vector<int>dp(k + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = coins[i]; j <= k; j++)
		{
			dp[j] += dp[j - coins[i]];
		}
	}

	cout << dp[k];
}