#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	int sizes[1001];
	for (int i = 0; i < n; i++) cin >> sizes[i];
	
	// dp[i]는 sizes[i]를 마지막 원소로 가질 때 최대증가수열의 값
	int dp[1001];
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;

		for (int j = 0; j < i; j++)
		{
			if (sizes[j] < sizes[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				if (ans < dp[i]) ans = dp[i];
			}
		}
	}

	cout << ans;
}