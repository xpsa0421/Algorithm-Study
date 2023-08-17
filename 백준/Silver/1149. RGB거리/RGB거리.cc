#include <iostream>
#include <vector>
using namespace std;

int dp[1001][3] = { 0 };
int costs[1001][3] = { 0 };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
	}

	dp[0][0] = costs[0][0];
	dp[0][1] = costs[0][1];
	dp[0][2] = costs[0][2];

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
	}

	int min_cost = min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
	cout << min_cost;
}