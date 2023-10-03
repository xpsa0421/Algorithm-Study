#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int n = 0, k = 0;
	cin >> n >> k;

	vector<int> values(n);
	for (int i = 0; i < n; i++) cin >> values[i];

	// solve
	vector<int> dp(k + 1, 10001);
	dp[0] = 0;

	for (int value : values)
	{
		if (value > k) continue;

		for (int i = value; i <= k; i++)
		{
			dp[i] = min(dp[i], dp[i - value] + 1);
		}
	}
	
	// output
	cout << (dp[k] == 10001 ? -1 : dp[k]);
	
}