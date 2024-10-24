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
	vector<int> liquids(n);
	for (int i = 0; i < n; i++)
		cin >> liquids[i];

	int st = 0, en = n - 1, minVal = 200000001;
	while (st < en)
	{
		int sum = liquids[st] + liquids[en];
		if (abs(sum) < abs(minVal))
		{
			minVal = sum;
			if (sum == 0) break;
		}
		if (sum < 0) st++;
		else en--;
	}

	cout << minVal;
}