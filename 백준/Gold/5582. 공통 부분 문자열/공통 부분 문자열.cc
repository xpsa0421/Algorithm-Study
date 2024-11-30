#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;

	int maxLen = 0;
	vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
	for (int i = 0; i < s1.length(); i++)
	{
		for (int j = 0; j < s2.length(); j++)
		{
			if (s1[i] == s2[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
				maxLen = max(dp[i + 1][j + 1], maxLen);
			}
		}
	}

	cout << maxLen;
}