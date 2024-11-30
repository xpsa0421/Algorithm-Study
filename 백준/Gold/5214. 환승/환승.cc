#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int n, k, m;
	cin >> n >> k >> m;

	vector<vector<int>> adj(n + m + 1);
	for (int i = 1; i <= m; i++)
	{
		int tube = n + i; int con;
		for (int j = 0; j < k; j++)
		{
			cin >> con;
			adj[tube].push_back(con);
			adj[con].push_back(tube);
		}
	}

	vector<int> dist(n + m + 1, -1);
	queue<int> q;
	q.push(1);
	dist[1] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		
		if (cur == n)
		{
			break;
		}

		for (int conn : adj[cur])
		{
			if (dist[conn] != -1) continue;
			if (conn > n) dist[conn] = dist[cur];
			else dist[conn] = dist[cur] + 1;
			q.push(conn);
		}
	}

	cout << dist[n];
}