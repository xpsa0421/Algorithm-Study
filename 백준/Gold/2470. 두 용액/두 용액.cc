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
	vector<int> liquids(n,0);
	vector<int> candLiquids; int curMin = 2000000000;
	for (int i = 0; i < n; i++) cin >> liquids[i];
	sort(liquids.begin(), liquids.end());

	int st = 0, en = n - 1;

	while (st < en)
	{
		int sum = liquids[st] + liquids[en];
		if (abs(sum) < curMin)
		{
			curMin = abs(sum);
			candLiquids = { liquids[st], liquids[en] };
			if (curMin == 0) break;
		}
		if (sum < 0) st++;
		else en--;
	}

	cout << candLiquids[0] << ' ' << candLiquids[1];
}