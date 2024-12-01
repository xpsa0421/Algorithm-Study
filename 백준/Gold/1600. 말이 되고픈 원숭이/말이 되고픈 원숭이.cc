#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int k, w, h;
	cin >> k >> w >> h;
	vector<vector<char>> map(h, vector<char>(w, ' '));
	for (int r = 0; r < h; r++)
		for (int c = 0; c < w; c++)
			cin >> map[r][c];
	
	vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(k + 1, -1)));
	queue<tuple<int, int, int>> toVisit; // r, c, k
	toVisit.emplace(0, 0, 0);
	dist[0][0][0] = 0;

	int hdr[] = { 1,2,2,1,-1,-2,-2,-1 };
	int hdc[] = { 2,1,-1,-2,-2,-1,1,2 };
	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };

	vector<tuple<int, int, int>> candidates;
	while (!toVisit.empty())
	{
		auto [r, c, d] = toVisit.front(); toVisit.pop();
		if (r == h - 1 && c == w - 1)
		{
			cout << dist[r][c][d];
			return 0;
		}

		if (d < k)
		{
			for (int i = 0; i < 8; i++)
				candidates.emplace_back(r + hdr[i], c + hdc[i], d + 1);
		}
		for (int i = 0; i < 4; i++)
			candidates.emplace_back(r + dr[i], c + dc[i], d);

		for (auto& [nr, nc, nd] : candidates)
		{
			if (nr < 0 || nc < 0 || nr >= h || nc >= w) continue;
			if (map[nr][nc] == '1') continue;
			if (dist[nr][nc][nd] != -1) continue;
			
			toVisit.emplace(nr, nc, nd);
			dist[nr][nc][nd] = dist[r][c][d] + 1;
		}
		candidates.clear();
	}

	cout << -1;
}