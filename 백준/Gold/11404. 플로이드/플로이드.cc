#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int costs[101][101];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		fill(costs[i], costs[i] + n + 1, INF);
		costs[i][i] = 0;
	}

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		costs[a][b] = min(costs[a][b], c);
	}

	for (int mid = 1; mid <= n; mid++)
	{
		for (int ori = 1; ori <= n; ori++)
		{
			for (int dst = 1; dst <= n; dst++)
			{
				if (costs[ori][dst] > costs[ori][mid] + costs[mid][dst])
					costs[ori][dst] = costs[ori][mid] + costs[mid][dst];
			}
		}
	}			
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (costs[i][j] == INF) cout << "0 ";
			else cout << costs[i][j] << ' ';
		}
		cout << '\n';
	}
}
