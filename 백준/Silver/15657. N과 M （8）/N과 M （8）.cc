#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
using namespace std;

int n, m;
int nums[8];
int ansIdx[8];

void solve(int k, int cur)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << nums[ansIdx[i]] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = cur; i < n; i++)
	{
		ansIdx[k] = i;
		solve(k + 1, i);
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