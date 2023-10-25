#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	long long dp[101][10];
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0) dp[i][0] = dp[i - 1][1];
			else if (j == 9) dp[i][9] = dp[i - 1][8];
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

			dp[i][j] %= 1000000000;
		}
	}	

	long long sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += dp[n][i];
		sum %= 1000000000;
	}

	cout << sum;
}

