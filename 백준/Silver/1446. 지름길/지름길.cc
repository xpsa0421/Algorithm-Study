#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

vector<pair<int, int>> adj[10001]; // cost, start
int dp[10001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, d;
	cin >> n >> d;
	while (n--)
	{
		int st, en, dst;
		cin >> st >> en >> dst;
		adj[en].push_back({ dst, st });
	}

	// for destination i
	for (int i = 1; i <= d; i++)
	{
		dp[i] = dp[i - 1] + 1;
		for (auto& [cost, start] : adj[i])
		{
			dp[i] = min(dp[i], dp[start] + cost);
		}
	}

	cout << dp[d];
}