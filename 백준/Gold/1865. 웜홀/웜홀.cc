#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
#define MAX 0x7f7f7f7f

vector<tuple<int, int, int>> edges; // from, to, cost
int dist[501];
int n, m, w;

bool hasNegativeCycle()
{
	fill(dist, dist + n + 1, 2000000000);
	for (int i = 1; i <= n; i++)
	{
		for (auto& [from, to, cost] : edges)
		{
			if (dist[to] > dist[from] + cost)
			{
				dist[to] = dist[from] + cost;
				if (i == n) return true;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc; cin >> tc;
	while (tc--)
	{
		cin >> n >> m >> w;
		edges.clear();

		for (int i = 0; i < m; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			edges.push_back({ s,e,t });
			edges.push_back({ e,s,t });
		}
		for (int i = 0; i < w; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			edges.push_back({ s,e,-t });
		}

		cout << (hasNegativeCycle() ? "YES\n" : "NO\n");
	}
}
