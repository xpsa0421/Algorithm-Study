#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// Input
	int n; cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	// Solve - DP
	vector<int> res;
	vector<int> record(n, 0);
	res.push_back(nums[0]);
	int maxLen = 1;
	for (int i = 1; i < n; i++)
	{
		if (res.back() >= nums[i])
		{
			auto it = lower_bound(res.begin(), res.end(), nums[i]);
			*it = nums[i];
			record[i] = it - res.begin();
		}
		else
		{
			res.push_back(nums[i]);
			record[i] = maxLen++;
		}
	}
	vector<int> lis; lis.reserve(n);
	int cur = maxLen - 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (record[i] == cur)
		{
			lis.push_back(nums[i]);
			cur--;
			if (cur == -1) break;
		}
	}

	// Output
	cout << maxLen << '\n';
	for (int i = maxLen - 1; i >= 0; i--)
		cout << lis[i] << ' ';
}