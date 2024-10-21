#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

long long infos[10];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string name, info;
		cin >> name >> info;

		for (int j = m - 1; j >= 0; j--)
		{
			infos[i] = (infos[i] << 1) | (info[j] == 'Y');
		}
	}
	
	int minCnt = n + 1, maxPlay = 1;
	for (int tmp = 0; tmp < (1 << n); tmp++)
	{
		long long res = 0;
		int cnt = 0, play = 0;
		for (int i = 0; i < n; i++)
		{
			if ((tmp >> i) & 1) // i번째 기타가 포함되는 조합이면
			{
				res |= infos[i];
				cnt++;
			}
		}

		for (int i = 0; i < m; i++)
		{
			if ((res >> i) & 1) play++;
		}

		if (play == maxPlay)
		{
			minCnt = min(minCnt, cnt);
		}
		else if (play > maxPlay)
		{
			maxPlay = play;
			minCnt = cnt;
		}
	}

	if (minCnt <= n) cout << minCnt;
	else cout << -1;
}
