#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
using namespace std;

int n, m;
int nums[9];
int ans[9];
bool isUsed[9];

// Fill in the kth element
void solve(int k)
{
	if (k > m)
	{
		for (int i = 1; i <= m; i++)
		{
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!isUsed[i] && ans[k-1] < nums[i])
		{
			ans[k] = nums[i];
			isUsed[i] = true;
			solve(k+1);
			isUsed[i] = false;			
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	sort(nums + 1, nums + 1 + n);
	solve(1);
}