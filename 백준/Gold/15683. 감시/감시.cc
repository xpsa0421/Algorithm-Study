#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, ans = 64;
int rotations[8]; // number of left rotations for each cam
int map[8][8];
int mapRes[8][8];
vector<pair<int, int>> cams;
int numRotTypes[6] = { 0, 4, 2, 4, 4, 1 };

int calc()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mapRes[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

// i [right, top, left, bottom]
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1, 0, -1, 0 };
void fill(int i, int x, int y)
{
	while (true)
	{
		x += dx[i];
		y += dy[i];
		if (x < 0 || x >= n || y < 0 || y >= m) break;
		if (map[x][y] == 6) break;
		if (map[x][y] == 0) mapRes[x][y] = -1;
	}
}

// K번 씨씨티비부터 조정
void solve(int k)
{
	// 마지막 씨씨티비까지 다 봤다면
	if (k == cams.size())
	{
		memcpy(mapRes, map, sizeof(map));
		for (int i = 0; i < cams.size(); i++)
		{
			int x = cams[i].first;
			int y = cams[i].second;

			switch (map[x][y])
			{
			case 1:
				fill(rotations[i], x, y);
				break;
			case 2:
				if (rotations[i] == 0)
				{
					fill(0, x, y);
					fill(2, x, y);
				}
				else
				{
					fill(1, x, y);
					fill(3, x, y);
				}
				break;
			case 3:
				if (rotations[i] == 0)
				{
					fill(0, x, y);
					fill(1, x, y);
				}
				else if (rotations[i] == 1)
				{
					fill(1, x, y);
					fill(2, x, y);
				}
				else if (rotations[i] == 2)
				{
					fill(2, x, y);
					fill(3, x, y);
				}
				else
				{
					fill(3, x, y);
					fill(0, x, y);
				}
				break;
			case 4:
				if (rotations[i] == 0)
				{
					fill(0, x, y);
					fill(1, x, y);
					fill(2, x, y);
				}
				else if (rotations[i] == 1)
				{
					fill(1, x, y);
					fill(2, x, y);
					fill(3, x, y);
				}
				else if (rotations[i] == 2)
				{
					fill(2, x, y);
					fill(3, x, y);
					fill(0, x, y);
				}
				else
				{
					fill(3, x, y);
					fill(0, x, y);
					fill(1, x, y);
				}
				break;
			case 5:
				fill(0, x, y);
				fill(1, x, y);
				fill(2, x, y);
				fill(3, x, y);
				break;
			}
		}
		ans = min(ans, calc());
		return;
	}

	auto pos = cams[k];
	int camType = map[pos.first][pos.second];
	for (int i = 0; i < numRotTypes[camType]; i++)
	{
		rotations[k] = i;
		solve(k + 1);
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
			if (map[i][j] != 0 && map[i][j] != 6)
			{
				cams.push_back({ i,j });
			}
		}
	}

	solve(0);
	cout << ans;
}