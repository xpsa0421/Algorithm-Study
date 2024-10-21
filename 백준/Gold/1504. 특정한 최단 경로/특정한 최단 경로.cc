#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define MAX 0x7f7f7f7f

int n, e;
vector<pair<int,int>> adj[801];

vector<int> dijkstra(int start)
{
	vector<int> dist(n + 1, MAX);
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int curC, curV;
		tie(curC, curV) = pq.top(); pq.pop();

		if (curC > dist[curV]) continue;

		for (auto& [nxtC, nxtV] : adj[curV])
		{
			if (dist[nxtV] <= dist[curV] + nxtC) continue;
			dist[nxtV] = dist[curV] + nxtC;
			pq.push({ dist[nxtV], nxtV });
		}
	}
	return dist;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> e;

	while (e--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({c, b});
		adj[b].push_back({ c, a });
	}

	int v1, v2;
	cin >> v1 >> v2;

	vector<int> distFromSt = dijkstra(1);
	vector<int> distFromV1 = dijkstra(v1);
	vector<int> distFromV2 = dijkstra(v2);

	if (distFromSt[v1] == MAX || distFromV1[v2] == MAX || distFromV2[n] == MAX)
	{
		cout << -1;
	}
	else
	{
		int a = distFromSt[v1] + distFromV1[v2] + distFromV2[n];
		int b = distFromSt[v2] + distFromV2[v1] + distFromV1[n];
		cout << min(a, b);
	}
}
