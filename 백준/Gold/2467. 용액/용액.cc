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
	vector<int> liquids(n, 0);
	for (int i = 0; i < n; i++)
		cin >> liquids[i];

	int sum = 2000000000; pair<int, int> ansLiquids;
	int left = 0, right = n - 1;
	while (left < right)
	{
		// Update sum
		int curSum = liquids[left] + liquids[right];
		if (abs(curSum) < sum)
		{
			sum = abs(curSum);
			ansLiquids = { liquids[left], liquids[right]};
			if (curSum == 0) break;
		}

		// Update pointers
		if (curSum < 0) left++;
		else right--;
	}

	cout << ansLiquids.first << ' ' << ansLiquids.second;
}