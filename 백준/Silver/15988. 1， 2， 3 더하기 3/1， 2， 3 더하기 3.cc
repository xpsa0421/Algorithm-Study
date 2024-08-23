#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	vector<long long> dp(1000002);
	dp[1] = 1; // 1
	dp[2] = 2; // 11, 2
	dp[3] = 4; // 111, 12, 21, 3


	for (int i = 4; i < 1000001; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		dp[i] %= 1000000009;
	}

	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;
		cout << dp[n] << '\n';
	}
}