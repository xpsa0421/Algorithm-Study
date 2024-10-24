#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <deque>
using namespace std;

int map[100][100];
int minCosts[100][100];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int m, n;
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = s[j] - '0';
		}
	}

	int MAX = n * m;
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) 
			minCosts[i][j] = MAX;
	
	deque<pair<int, int>> dq;
	dq.push_back({ 0,0 }); // start pos
	minCosts[0][0] = 0;

	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };
	while (!dq.empty())
	{
		int curR, curC;
		tie(curR, curC) = dq.front();
		dq.pop_front();

		// search adj
		for (int i = 0; i < 4; i++)
		{
			int nextR = curR + dr[i];
			int nextC = curC + dc[i];
			if (nextR < 0 || nextR == n || nextC < 0 || nextC == m) continue;

			int cost = minCosts[curR][curC] + map[nextR][nextC];
			if (minCosts[nextR][nextC] > cost)
			{
				minCosts[nextR][nextC] = cost;
				if (map[nextR][nextC] == 0) dq.push_front({ nextR, nextC });
				else dq.push_back({ nextR, nextC });
			}
		}
	}

	cout << minCosts[n - 1][m - 1];
}