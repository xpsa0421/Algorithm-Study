#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int len[50][50];
int map[50][50];
int visited[50][50];

void Init()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	int nextIOffsets[] = { -1,-1,0,1,1,1,0,-1 };
	int nextJOffsets[] = { 0,1,1,1,0,-1,-1,-1 };
	int ans = 0;
	queue<pair<int, int>> toVisit;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				Init();
				visited[i][j] = true;
				len[i][j] = 0;
				toVisit.emplace(i, j);

				while (!toVisit.empty())
				{
					int curI = toVisit.front().first;
					int curJ = toVisit.front().second;
					toVisit.pop();

					for (int k = 0; k < 8; k++)
					{
						int nextI = curI + nextIOffsets[k];
						int nextJ = curJ + nextJOffsets[k];

						if (nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= m) continue;
						if (visited[nextI][nextJ]) continue;
						if (map[nextI][nextJ] == 1)
						{
							ans = max(ans, len[curI][curJ] + 1);
							while (!toVisit.empty()) toVisit.pop();
							break;
						}

						len[nextI][nextJ] = len[curI][curJ] + 1;
						visited[nextI][nextJ] = true;
						toVisit.emplace(nextI, nextJ);
					}
				}
			}
		}
	}

	cout << ans;
}