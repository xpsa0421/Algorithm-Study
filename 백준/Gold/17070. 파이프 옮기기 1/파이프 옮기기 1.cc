#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
 
// 01:37
int n;
int map[16][16];
int ans = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	queue<tuple<int, int, int>> toVisit; // r, c, shape
	toVisit.push({ 0,1,0 });
	
	while (!toVisit.empty())
	{
		auto cur = toVisit.front(); toVisit.pop();
		int curR = get<0>(cur), curC = get<1>(cur), curS = get<2>(cur);

		// Base condition
		if (curR == n - 1 && curC == n - 1)
		{
			ans++;
			continue;
		}

		// 가로
		int nexR, nexC, nexS;
		if (curS != 1)
		{
			nexR = curR, nexC = curC + 1, nexS = 0;
			if (nexC != n && map[nexR][nexC] == 0)
				toVisit.push({ nexR, nexC, nexS });
		}

		// 세로
		if (curS != 0)
		{
			nexR = curR + 1, nexC = curC, nexS = 1;
			if (nexR != n && map[nexR][nexC] == 0)
				toVisit.push({ nexR, nexC, nexS });
		}

		// 대각선
		nexR = curR + 1, nexC = curC + 1, nexS = 2;
		if (nexR != n && nexC != n &&
			(map[nexR][nexC] == 0 && map[curR][nexC] == 0 && map[nexR][curC] == 0))
			toVisit.push({ nexR, nexC, nexS });
	}

	cout << ans;
}
