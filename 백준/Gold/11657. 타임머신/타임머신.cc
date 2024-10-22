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
long long dist[501];
int n, m, w;

bool bellmanFord()
{
	fill(dist, dist + n + 1, MAX);
	dist[1] = 0;
	for (int i = 0; i < n; i++)
	{
		for (auto& [from, to, cost] : edges)
		{
			if (dist[from] == MAX) continue;
			if (dist[to] > dist[from] + cost)
			{
				dist[to] = dist[from] + cost;
				if (i == n - 1) return true;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e, t;
		cin >> s >> e >> t;
		edges.push_back({ s,e,t });
	}

	if (bellmanFord())
	{
		cout << "-1\n";
	}
	else
	{
		for (int i = 2; i <= n; i++)
			cout << (dist[i] == MAX ? -1 : dist[i]) << '\n';
	}
}
