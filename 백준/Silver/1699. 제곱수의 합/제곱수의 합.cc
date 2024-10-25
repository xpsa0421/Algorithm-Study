#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = i;
		 for (int j = 1; j * j <= i; j++)
			dp[i] = min(dp[i], dp[i - j*j] + 1);
	}

	cout << dp[n];
}
