#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int map[8][8];
vector<pair<int, int>> blanks;
vector<pair<int, int>> viruses;

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int search()
{
	bool visited[8][8] = {};
	int infectCnt = 0;
	queue<pair<int, int>> toVisit;

	for (auto& [stR, stC] : viruses)
	{
		visited[stR][stC] = true;
		toVisit.push({ stR, stC });

		while (!toVisit.empty())
		{
			int curR, curC;
			tie(curR, curC) = toVisit.front(); toVisit.pop();

			for (int i = 0; i < 4; i++)
			{
				int nexR = curR + dr[i];
				int nexC = curC + dc[i];
				if (nexR < 0 || nexR == n || nexC < 0 || nexC == m) continue;
				if (visited[nexR][nexC]) continue;
				if (map[nexR][nexC] != 0) continue;
				
				toVisit.push({nexR, nexC});
				visited[nexR][nexC] = true;
				infectCnt++;
			}
		}
	}
	
	int safeCnt = blanks.size() - 3 - infectCnt;
	return safeCnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// Input
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0) blanks.push_back({ i,j });
			else if (map[i][j] == 2) viruses.push_back({ i,j });
		}
	}

	// Solve
	int maxSafeCnt = 0;
	int numBlanks = blanks.size();
	for (int i = 0; i < numBlanks - 2; i++)
	{
		map[blanks[i].first][blanks[i].second] = 1;
		for (int j = i + 1; j < numBlanks - 1; j++)
		{
			map[blanks[j].first][blanks[j].second] = 1;
			for (int k = j + 1; k < numBlanks; k++)
			{
				map[blanks[k].first][blanks[k].second] = 1;
				maxSafeCnt = max(maxSafeCnt, search());
				map[blanks[k].first][blanks[k].second] = 0;
			}
			map[blanks[j].first][blanks[j].second] = 0;
		}
		map[blanks[i].first][blanks[i].second] = 0;
	}

	// Output
	cout << maxSafeCnt;
}
