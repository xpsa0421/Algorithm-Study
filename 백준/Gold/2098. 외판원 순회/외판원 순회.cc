#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// dp[visited][i]:	현재까지 방문한 도시가 visited(bitmask)일 때,
//					마지막으로 방문한 도시가 i인 경우의 최소 비용
vector<vector<int>> dp;
vector<vector<int>> dist;
int n;
const int MAX = 16 * 1000000 + 1;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// Input
	cin >> n;
	dist.resize(n, vector<int>(n, 0));
	dp.assign(1 << n, vector<int>(n, MAX));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> dist[i][j];

	// Solve
	dp[1][0] = 0; // Start City
	
	// 모든 visited 상태에 대해 dp 업데이트
	for (int visited = 1; visited < (1 << n); visited++)
	{
		// 모든 최근 방문 도시에 대해
		for (int last = 0; last < n; last++)
		{
			// 방문한 도시가 아니라면 스킵
			if (!(visited & (1 << last))) continue;

			// 최근 방문 도시에서 갈 수 있는 다른 도시 탐색
			for (int next = 0; next < n; next++)
			{
				if (next == last || (visited & (1 << next)) || dist[last][next] == 0) continue;
				int nextVisited = visited | (1 << next);
				dp[nextVisited][next] = min(dp[nextVisited][next], dp[visited][last] + dist[last][next]);
			}
		}
	}

	// 시작 도시로 돌아오기
	int minCost = MAX;
	for (int last = 1; last < n; last++)
	{
		if (dist[last][0] == 0) continue;
		minCost = min(minCost, dp[(1 << n) - 1][last] + dist[last][0]);
	}

	// Output
	cout << minCost;
}
