#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <list>
#include <deque>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> nums(n,0);
	for (int i = 0; i < n; i++) cin >> nums[i];
	sort(nums.begin(), nums.end());
	
	vector<int> twoSums;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			twoSums.push_back(nums[i] + nums[j]);
		}
	}
	sort(twoSums.begin(), twoSums.end());

	int ans = 0;
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (binary_search(twoSums.begin(), twoSums.end(), nums[i] - nums[j]))
			{
				cout << nums[i];
				return 0;
			}
		}
	}
}