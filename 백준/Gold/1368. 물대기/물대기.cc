#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> adj[301];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // cost, b
bool isConnected[301];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int costSelf = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> costSelf;
		adj[i].push_back({ costSelf, 0 });
		adj[0].push_back({ costSelf, i });
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int c; cin >> c;
			if (i >= j) continue;
			adj[i].push_back({ c, j });
			adj[j].push_back({ c, i });
		}
	}

	// 처음 우물을 만드는 경우
	for (auto con : adj[0]) pq.push(con);
	isConnected[0] = true;

	int cnt = 0, totalCost = 0;
	while (cnt < n)
	{
		int cost, to;
		tie(cost, to) = pq.top(); pq.pop();
		if (isConnected[to]) continue;

		isConnected[to] = true;
		cnt++; totalCost += cost;

		for (auto& next : adj[to])
		{
			if (!isConnected[next.second]) pq.push(next);
		}
	}

	cout << totalCost;
}
