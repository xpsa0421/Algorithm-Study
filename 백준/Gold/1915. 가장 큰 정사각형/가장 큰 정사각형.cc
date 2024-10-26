#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int nums[1001][1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// Input
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string s; cin >> s;
		for (int j = 1; j <= m; j++)
			nums[i][j] = s[j-1] - '0';
	}

	// Solve - DP
	int maxLen = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (nums[i][j] == 1)
			{
				nums[i][j] = min(nums[i - 1][j - 1], min(nums[i - 1][j], nums[i][j - 1])) + 1;
				maxLen = max(maxLen, nums[i][j]);
			}
		}
	}

	// Output
	cout << maxLen * maxLen;
}
