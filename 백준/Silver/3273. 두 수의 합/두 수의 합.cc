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
	
	int n; cin >> n;
	vector<int> nums(n,0);
	for (int i = 0; i < n; i++) cin >> nums[i];
	sort(nums.begin(), nums.end());

	int x; cin >> x;
	int ans = 0, lo = 0, hi = n - 1;
	while (lo < hi)
	{
		int sum = nums[lo] + nums[hi];
		if (sum == x)
		{
			ans++;
			lo++;
		}
		else if (sum < x)
		{
			lo++;
		}
		else
		{
			hi--;
		}
	}

	cout << ans;
}