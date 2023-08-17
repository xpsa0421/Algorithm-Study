#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	int max_dp = 1;
	vector<int> nums(n);
	vector<int> dp_increasing(n, 1);
	vector<int> dp_decreasing(n, 1);

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	// 임의의 위치 idx까지 증가하는 수열
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] > nums[j])
			{
				dp_increasing[i] = max(dp_increasing[i], dp_increasing[j] + 1);
			}
		}
	}

	// 임의의 위치 idx부터 감소하는 수열
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (nums[i] > nums[j])
			{
				dp_decreasing[i] = max(dp_decreasing[i], dp_decreasing[j] + 1);
			}
		}
	}

	// 최장 바이토닉 수열
	for (int i = 0; i < n; i++)
	{
		max_dp = max(max_dp, dp_increasing[i] + dp_decreasing[i] - 1);
	}

	cout << max_dp;
}