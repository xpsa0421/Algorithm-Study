#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int nums[4][4000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// input
	int n; cin >> n;
	for (int j = 0; j < n; j++)
		for (int i = 0; i < 4; i++)
			cin >> nums[i][j];

	// a + b | c + d
	vector<int> ab; ab.reserve(n * n);
	vector<int> cd; cd.reserve(n * n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ab.push_back(nums[0][i] + nums[1][j]);
			cd.push_back(nums[2][i] + nums[3][j]);
		}
	}
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	// a + b + c + d == 0?
	long long ans = 0;
	for (int abSum : ab)
	{
		auto range = equal_range(cd.begin(), cd.end(), -abSum);
		ans += distance(range.first, range.second);
	}

	cout << ans << '\n';
}