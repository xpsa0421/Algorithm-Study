#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int t = 0, w = 0;
	cin >> t >> w;
	vector<int> falls(t+1, 0);
	for (int i = 1; i <= t; i++) cin >> falls[i];

	// solve
	vector<vector<int>> dp(t+1, vector<int>(w+1, 0));

	// 한번도 안 움직이는 경우에 받는 자두의 수 초기화
	for (int i = 1; i <= t; i++)
	{
		dp[i][0] = (falls[i] == 1) ? dp[i - 1][0] + 1 : dp[i - 1][0];
	}

	for (int i = 1; i <= t; i++)
	{
		int fall_tree = falls[i];
		for (int num_moves = 1; num_moves <= w; num_moves++)
		{
			// 알맞은 나무 아래에 있는 경우
			if (num_moves % 2 == fall_tree - 1) 
			{
				dp[i][num_moves] = max(dp[i - 1][num_moves], dp[i - 1][num_moves - 1]) + 1;
			}
			// 다른 나무 밑에 있는 경우
			else 
			{
				dp[i][num_moves] = max(dp[i - 1][num_moves], dp[i - 1][num_moves - 1]);
			}
		}
	}
	
	// output
	int ret = 0;
	for (int num_moves = 0; num_moves <= w; num_moves++)
		ret = max(ret, dp[t][num_moves]);
	cout << ret;
}