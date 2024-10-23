#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

bool palinDP[2001][2001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> nums(n,0);
	for (int i = 0; i < n; i++) cin >> nums[i];

	// Cnt 1
	for (int i = 0; i < n; i++)
		palinDP[i][i] = true;

	// Cnt 2
	for (int i = 0; i < n - 1; i++)
		if (nums[i] == nums[i + 1]) palinDP[i][i + 1] = true;

	// Cnt over 3
	for (int len = 3; len <= n; len++)
	{
		for (int i = 0; i <= n - len; i++)
		{
			int j = i + len - 1;
			palinDP[i][j] = (nums[i] == nums[j]) && palinDP[i + 1][j - 1];
		}
	}

	int m; cin >> m;
	while (m--)
	{
		int s, e;
		cin >> s >> e;
		cout << (palinDP[s - 1][e - 1] ? 1 : 0) << '\n';
	}
}