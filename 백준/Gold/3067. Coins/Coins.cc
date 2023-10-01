#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int test_cases = 0;
	cin >> test_cases;

	// solve
	vector<int> answers;
	while (test_cases--)
	{
		int num_cointypes = 0;
		cin >> num_cointypes;

		vector<int> cointypes(num_cointypes, 0);
		for (int i = 0; i < num_cointypes; i++) cin >> cointypes[i];

		int target = 0;
		cin >> target;

		vector<int> dp(target + 1, 0);
		for (int coin : cointypes)
		{
			if (coin > target) continue;

			dp[coin]++;
			for (int i = coin; i <= target; i++)
			{
				dp[i] = dp[i] + dp[i - coin];
			}
		}

		answers.push_back(dp[target]);
	}

	// output
	for (int ans : answers)
	{
		cout << ans << "\n";
	}
}