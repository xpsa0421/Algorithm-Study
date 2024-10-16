#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
using namespace std;

int n, m;
int nums[7];
int ans[7];

void solve(int k)
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

	for (int i = 0; i < n; i++)
	{
		ans[k] = nums[i];
		solve(k + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> nums[i];
	sort(nums, nums + n);

	solve(0);
}