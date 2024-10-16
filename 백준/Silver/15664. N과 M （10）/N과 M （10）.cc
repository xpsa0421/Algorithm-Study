#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
using namespace std;

int n, m;
int nums[8];
int ans[8];

void solve(int k, int cur)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int prev = -1;
	for (int i = cur; i < n; i++)
	{
		if (prev != nums[i])
		{
			ans[k] = prev = nums[i];
			solve(k + 1, i + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> nums[i];
	sort(nums, nums + n);
	solve(0, 0);
}