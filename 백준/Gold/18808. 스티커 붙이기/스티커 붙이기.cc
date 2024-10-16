#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, k, r, c;
int note[40][40];
int sticker[10][10];
int tmp[10][10];

bool isPastable(int startR, int startC)
{
	for (int dr = 0; dr < r; dr++)
	{
		for (int dc = 0; dc < c; dc++)
		{
			if (sticker[dr][dc] == 1 && note[startR + dr][startC + dc] == 1)
				return false;
		}
	}
	return true;
}

void paste(int startR, int startC)
{
	for (int dr = 0; dr < r; dr++)
	{
		for (int dc = 0; dc < c; dc++)
		{
			if (sticker[dr][dc] == 1)
				note[startR + dr][startC + dc] = 1;
		}
	}
}

void rotate()
{
	memcpy(tmp, sticker, sizeof(sticker));
	for (int x = 0; x < c; x++)
	{
		for (int y = 0; y < r; y++)
		{
			sticker[x][y] = tmp[r - 1 - y][x];
		}
	}
	swap(r, c);
}

int count()
{
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ans += note[i][j];
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> k;
	while (k--)
	{
		cin >> r >> c;

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> sticker[i][j];

		for (int rot = 0; rot < 4; rot++)
		{
			bool pasted = false;
			for (int i = 0; i <= n - r; i++)
			{
				if (pasted) break;
				for (int j = 0; j <= m - c; j++)
				{
					if (isPastable(i, j))
					{
						paste(i,j);
						pasted = true;
						break;
					}
				}
			}
			if (pasted) break;
			rotate();
		}
	}

	cout << count();
}