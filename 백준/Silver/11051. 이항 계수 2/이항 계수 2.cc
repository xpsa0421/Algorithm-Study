#include <iostream>
#include <vector>
using namespace std;

int dp[1001][1001];
int mod = 10007;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	// dp[i][j] = iCj -> nCk
	// dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
		}
	}

	cout << dp[n][k];
}
