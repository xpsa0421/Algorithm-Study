#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 1001;

int dp[1001][3];
int cost[1001][3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// dp[i][j] is the minimum cost for painting until home[i] with [j]
	// where i = 0:N (home), j = 0,1,2 (colour: red, green, blue)
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	int minTotal = 1001 * 1000;

	// house #1: RED
	dp[1][0] = cost[1][0]; dp[1][1] = MAX; dp[1][2] = MAX;
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}
	minTotal = min(minTotal, min(dp[n][1], dp[n][2]));

	// house #1: GREEN
	dp[1][0] = MAX; dp[1][1] = cost[1][1]; dp[1][2] = MAX;
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}
	minTotal = min(minTotal, min(dp[n][0], dp[n][2]));

	// house #1: BLUE
	dp[1][0] = MAX; dp[1][1] = MAX; dp[1][2] = cost[1][2];
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}
	minTotal = min(minTotal, min(dp[n][0], dp[n][1]));

	cout << minTotal;
}