#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dp[5001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	string codeStr;
	cin >> codeStr;
	int codeSize = codeStr.size();
	codeStr = "0" + codeStr;

	vector<int> code(codeSize + 1);
	for (int i = 1; i <= codeSize; i++)
	{
		code[i] = codeStr[i] - '0';
	}

	dp[0] = 1;
	// dp[i]: i번째 암호까지 봤을 때 해석의 경우의 수
	for (int i = 1; i <= codeSize; i++)
	{
		// 두 자리로 해석 가능한 경우
		if (i != 1 && code[i-1] != 0)
		{
			int a = code[i - 1] * 10 + code[i];
			if (a <= 26)
			{
				dp[i] += dp[i - 2];
				dp[i] %= 1000000;
			}
		}

		// 한 자리로 해석하는 경우
		if (code[i] != 0)
		{
			dp[i] += dp[i - 1];
			dp[i] %= 1000000;
		}
	}

	cout << dp[codeSize];
}