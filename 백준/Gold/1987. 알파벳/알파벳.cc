#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <unordered_set>
using namespace std;
#define MAX 0x7f7f7f7f

int r, c;
char map[20][20];
bool alphs[26];
int maxCnt = 0;

int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

void dfs(int curR, int curC, int count)
{
	maxCnt = max(maxCnt, count);
	alphs[map[curR][curC] - 'A'] = true;

	for (int i = 0; i < 4; i++)
	{
		int nxtR = curR + dr[i], nxtC = curC + dc[i];
		if (nxtR < 0 || nxtR == r || nxtC < 0 || nxtC == c) continue;
		if (alphs[map[nxtR][nxtC] - 'A']) continue;
		
		dfs(nxtR, nxtC, count + 1);
		alphs[map[nxtR][nxtC] - 'A'] = false;
	}
	//alphs[map[curR][curC] - 'A'] = false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> map[i][j];

	dfs(0, 0, 1);
	cout << maxCnt;
}
