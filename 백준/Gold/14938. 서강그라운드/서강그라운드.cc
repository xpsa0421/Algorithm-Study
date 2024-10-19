#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int dists[101][101];
int items[101];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
	{
		fill(dists[i], dists[i] + 1 + n, INF);
		dists[i][i] = 0;
	}

	for (int i = 1; i <= n; i++) cin >> items[i];
	while (r--)
	{
		int a, b, l;
		cin >> a >> b >> l;
		dists[a][b] = l;
		dists[b][a] = l;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dists[i][j] > dists[i][k] + dists[k][j])
				{
					dists[i][j] = dists[i][k] + dists[k][j];
				}
			}
		}
	}

	int maxCollected = 0;
	for (int i = 1; i <= n; i++)
	{
		int collected = 0;
		for (int j = 1; j <= n; j++)
		{
			if (dists[i][j] > m) continue;
			collected += items[j];
		}
		maxCollected = max(maxCollected, collected);
	}

	cout << maxCollected;
}
