#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dp[10001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// Solve - DP
	dp[0] = 1;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 10000; j++)
			dp[j] += dp[j - i];
	
	// Output
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		cout << dp[n] << '\n';
	}
}
