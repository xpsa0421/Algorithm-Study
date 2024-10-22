#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
#define MAX 0x7f7f7f7f

int n, m, x;
vector<pair<int, int>> adj[10001];
vector<pair<int, int>> adjRev[10001];
int dist[10001];
int distRev[10001];

void dijkstra(int distance[], vector<pair<int,int>>* adjGraph)
{
	fill(distance, distance + n + 1, MAX);
	distance[x] = 0;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // time, vertex
	pq.push({ 0, x });

	while (!pq.empty())
	{
		int curT, curV;
		tie(curT, curV) = pq.top(); pq.pop();
		if (distance[curV] != curT) continue;

		for (auto& [cost, nextV] : adjGraph[curV])
		{
			if (distance[nextV] <= distance[curV] + cost) continue;
			distance[nextV] = distance[curV] + cost;
			pq.push({ distance[nextV], nextV });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x;
	while (m--)
	{
		int st, en, t;
		cin >> st >> en >> t;
		adj[st].push_back({ t, en });
		adjRev[en].push_back({ t, st });
	}
	dijkstra(dist, adj);
	dijkstra(distRev, adjRev);

	int maxDist = -1;
	for (int i = 1; i <= n; i++)
	{
		maxDist = max(maxDist, dist[i] + distRev[i]);
	}

	cout << maxDist;
}
