#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int n = 0;
	cin >> n;

	vector<int> dp(n,0);
	int max_dp = -1000;

	// solve
	for (int i = 0; i < n; i++)
	{
		cin >> dp[i];
		if (i != 0)
		{
			dp[i] = max(dp[i - 1] + dp[i], dp[i]);
		}
		max_dp = max(max_dp, dp[i]);
	}
	
	cout << max_dp;
}