#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	vector<int> durations(n, 0);
	vector<int> profits(n, 0);
	vector<int> dp(n + 1, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> durations[i] >> profits[i];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if (i + durations[i] > n)
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			dp[i] = max(dp[i + durations[i]] + profits[i], dp[i + 1]);
		}
	}

	cout << dp[0];
}