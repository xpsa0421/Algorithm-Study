#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m, k, x;
	cin >> n >> m >> k >> x;

	vector<vector<int>> adj(n+1);
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	vector<int> dist(n + 1, -1);
	queue<int> toVisit;
	dist[x] = 0;
	toVisit.push(x);

	vector<int> ans;
	while (!toVisit.empty())
	{
		int cur = toVisit.front(); toVisit.pop();
		if (dist[cur] == k)
		{
			ans.push_back(cur);
			continue;
		}

		for (int nxt : adj[cur])
		{
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			toVisit.push(nxt);
		}
	}

	if (ans.empty()) cout << -1;
	else
	{
		sort(ans.begin(), ans.end());
		for (int num : ans) cout << num << '\n';
	}
}