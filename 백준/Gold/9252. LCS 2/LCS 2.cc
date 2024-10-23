#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	for (int i = 1; i <= a.size(); i++)
	{
		for (int j = 1; j <= b.size(); j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j-1]);
			}
		}
	}

	// string
	string res = "";
	int i = a.size(), j = b.size();
	while (dp[i][j])
	{
		if (dp[i][j] == dp[i - 1][j])
			i--;
		else if (dp[i][j] == dp[i][j - 1])
			j--;
		else
		{
			i--; j--;
			res = a[i] + res;
		}
	}

	cout << res.size() << '\n' << res;
}