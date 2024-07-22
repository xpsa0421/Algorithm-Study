#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	// 시작은 SK -> CY
	// dp[a] = b에서 a는 돌의 개수, b는 a개의 돌을 가져가는 최소의 횟수
	int dp[1001];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	
	for (int i = 3; i <= n; i++)
	{
		// 1개를 가져가거나 3개를 가져가거나
		dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
	}

	cout << (dp[n] % 2 == 0 ? "CY" : "SK");
}