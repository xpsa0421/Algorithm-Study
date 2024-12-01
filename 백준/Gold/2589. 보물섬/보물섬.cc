#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

int rSize, cSize;
string map[50];
int maxDist;
int distances[50][50];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void search(int startR, int startC)
{
	queue<pair<int, int>> toVisit;
	toVisit.emplace(startR, startC);
	distances[startR][startC] = 1;

	while (!toVisit.empty())
	{
		auto[cr, cc] = toVisit.front();
		toVisit.pop();
		int dist = distances[cr][cc];

		if (dist > maxDist)
		{
			maxDist = dist;
		}

		for (int i = 0; i < 4; i++)
		{
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (nr < 0 || nr == rSize || nc < 0 || nc == cSize) continue;
			if (map[nr][nc] == 'W') continue;
			if (distances[nr][nc] != 0) continue;

			distances[nr][nc] = dist + 1;
			toVisit.emplace(nr, nc);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> rSize >> cSize;
	for (int r = 0; r < rSize; r++)
	{
		cin >> map[r];
	}
	
	for (int r = 0; r < rSize; r++)
	{
		for (int c = 0; c < cSize; c++)
		{
			if (map[r][c] == 'W') continue;

			search(r, c);
			memset(distances, 0, sizeof(distances));
		}
	}

	cout << maxDist - 1;
}