#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int map[1000][1000];
bool visited[1000][1000];
int numLinked[1000000];
int linkIndex[1000][1000];
int numGo[1000][1000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// Input
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		for (int j = 0; j < m; j++)
			map[i][j] = s[j] - '0';
	}

	// 0 먼저 구하기
	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };
	int unused = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1) continue;
			if (visited[i][j]) continue;
			
			queue<pair<int, int>> toVisit;
			toVisit.push({ i,j });
			visited[i][j] = true;
			int cnt = 0;
			int link = ++unused;

			while (!toVisit.empty())
			{
				int r, c;
				tie(r, c) = toVisit.front(); toVisit.pop();
				cnt++;
				linkIndex[r][c] = link;

				for (int i = 0; i < 4; i++)
				{
					int nr = r + dr[i];
					int nc = c + dc[i];

					if (nr < 0 || nr == n || nc < 0 || nc == m) continue;
					if (map[nr][nc] == 1) continue;
					if (visited[nr][nc]) continue;
					visited[nr][nc] = true;
					toVisit.push({ nr,nc });
				}
			}
			numLinked[link] = cnt % 10;
		}
	}

	// 1 구하기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0) continue;
			unordered_set<int> visitedLinks;
			numGo[i][j] = 1;

			for (int k = 0; k < 4; k++)
			{
				int nr = i + dr[k];
				int nc = j + dc[k];

				if (nr < 0 || nr == n || nc < 0 || nc == m) continue;
				if (map[nr][nc] == 1) continue;
				int lidx = linkIndex[nr][nc];
				if (visitedLinks.find(lidx) == visitedLinks.end())
				{
					numGo[i][j] += numLinked[linkIndex[nr][nc]];
					numGo[i][j] %= 10;
					visitedLinks.insert(lidx);
				}
			}
		}
	}

	// Output
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << numGo[i][j];
		}
		cout << '\n';
	}
}