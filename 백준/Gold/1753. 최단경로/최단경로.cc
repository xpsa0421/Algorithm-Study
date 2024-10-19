#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 1e9+10

vector<pair<int, int>> edges[20001]; // cost, nxt
int minCosts[20001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int v, e, k;
	cin >> v >> e >> k;

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back({ w, v });
	}

	fill(minCosts, minCosts + v + 1, INF);
	minCosts[k] = 0; // start pos
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // cost, vertex
	pq.push({ 0,k });

	while (!pq.empty())
	{
		int curC, curV;
		tie(curC, curV) = pq.top(); pq.pop();
		if (minCosts[curV] != curC) continue;

		for (auto& [cToNext, nextV] : edges[curV])
		{
			if (minCosts[nextV] > minCosts[curV] + cToNext)
			{
				minCosts[nextV] = minCosts[curV] + cToNext;
				pq.push({ minCosts[nextV], nextV });
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (minCosts[i] == INF) cout << "INF\n";
		else cout << minCosts[i] << '\n';
	}
}
