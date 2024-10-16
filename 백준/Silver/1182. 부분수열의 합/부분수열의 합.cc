#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, ans;
int nums[20];

void solve(int k, int curSum)
{
	if (k == n)
	{
		if (curSum == s) ans++;
		return;
	}

	solve(k + 1, curSum + nums[k]);
	solve(k + 1, curSum);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> nums[i];
	solve(0, 0);

	if (s == 0) ans--;
	cout << ans;
}