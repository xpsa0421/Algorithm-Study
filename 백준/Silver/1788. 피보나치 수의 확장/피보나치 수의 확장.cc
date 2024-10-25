#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// Input
	const int MOD = 1000000000;
	int n; cin >> n;
	int absN = abs(n);

	// Solve - DP
	vector<int> dp(absN + 2, 0);
	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i <= absN; i++)
		dp[i] = (dp[i - 1] % MOD + dp[i - 2] % MOD) % MOD;

	// Output
	if (n == 0) cout << 0 << '\n';
	else if (n < 0 && (n % 2 == 0)) cout << -1 << '\n'; //짝수 음수면 -ve
	else cout << 1 << '\n';
	cout << dp[absN];
}
