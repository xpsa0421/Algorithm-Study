#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

string map[1000];
bool visited[1000][1000][11];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		cin >> map[i];

	queue<tuple<int,int,int, int>> q; // r, c, numBreaks, distance
	q.push({ 0,0,0,1 });
	visited[0][0][0] = true;
	int minDist = 1000001;

	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };
	while (!q.empty())
	{
		int r, c, cnt, dist;
		tie(r, c, cnt, dist) = q.front(); q.pop();
		
		if (r == n - 1 && c == m - 1)
		{
			minDist = dist;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nextR = r + dr[i], nextC = c + dc[i];
			if (nextR < 0 || nextR == n || nextC < 0 || nextC == m) continue;
			
			if (map[nextR][nextC] == '1')
			{
				if (cnt < k && !visited[nextR][nextC][cnt + 1])
				{
					visited[nextR][nextC][cnt + 1] = true;
					q.push({ nextR, nextC, cnt + 1, dist + 1 });
				}
			}
			else
			{
				if (visited[nextR][nextC][cnt]) continue;
				visited[nextR][nextC][cnt] = true;
				q.push({ nextR, nextC, cnt, dist + 1 });
			}
		}
	}

	cout << (minDist == 1000001 ? -1 : minDist);
}