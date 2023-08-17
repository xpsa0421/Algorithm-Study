#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int dp[50001] = { 0 };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	int i = 2;
	int curr_max = 1;

	dp[1] = 1;
	while (i <= n)
	{
		if (i == pow(curr_max + 1, 2))
		{
			dp[i] = 1;
			curr_max++;
		}
		else
		{
			int best_max = curr_max;
			int max_pow = pow(best_max--, 2);
			dp[i] = dp[i - max_pow] + 1;

			while (dp[i] != 2 && best_max >= 2)
			{
				max_pow = pow(best_max--, 2);
				dp[i] = min(dp[i], dp[i - max_pow] + 1);
			}
		}
		i++;
	}

	cout << dp[n];
}
