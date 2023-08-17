#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	int max_dp = 0;
	vector<int> nums(n);
	vector<int> dp(n);

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
		dp[i] = nums[i];
		max_dp = max(max_dp, dp[i]);
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] > nums[j])
			{
				dp[i] = max(dp[i], dp[j] + nums[i]);
				max_dp = max(max_dp, dp[i]);
			}
		}
	}

	cout << max_dp;
}