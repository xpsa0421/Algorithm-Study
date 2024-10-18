#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int V, E;
vector<int> adj[20001];
int colors[20001]; // 1 or -1; 0 if unvisited

bool CheckBipartite()
{
	queue<int> toVisit;
	for (int i = 1; i <= V; i++)
	{
		if (colors[i] != 0) continue; // already visited
		colors[i] = 1;
		toVisit.push(i);

		while (!toVisit.empty())
		{
			int cur = toVisit.front();
			toVisit.pop();
			for (int nxt : adj[cur])
			{
				if (colors[nxt] == colors[cur]) return false;
				if (colors[nxt] != 0) continue;
				colors[nxt] = -colors[cur];
				toVisit.push(nxt);
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int k;
	cin >> k;

	while (k--)
	{
		memset(adj, 0, sizeof(adj));
		memset(colors, 0, sizeof(colors));
		cin >> V >> E;
		
		int u, v;
		for (int i = 0; i < E; i++)
		{
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		if (CheckBipartite()) cout << "YES\n";
		else cout << "NO\n";	
	}
}
