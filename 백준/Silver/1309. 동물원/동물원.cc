#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dp[100001][3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	// [0]: XX  |  [1]: OX  |  [2]: XO
	dp[1][0] = dp[1][1] = dp[1][2] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
	}

	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % 9901;
}