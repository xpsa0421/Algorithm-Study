#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int n = 0, m = 0;
	cin >> n >> m;

	vector<int> nums(n,0);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	// solve
	sort(nums.begin(), nums.end());
	int min_diff = 2000000000;

	for (auto iter = nums.begin(); iter != nums.end(); iter++)
	{
		auto lower = lower_bound(iter, nums.end(), *iter + m);
		if (lower != nums.end())
		{
			min_diff = min(min_diff, *lower - *iter);
			if (min_diff == m) break;
		}
	}
	
	// output
	cout << min_diff;
}