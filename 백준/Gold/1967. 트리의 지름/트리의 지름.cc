#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define MAX 0x7f7f7f7f

int maxDist = 0;
int maxIdx = 0;
vector<pair<int, int>> adj[10001];

void dfs(int cur, int par, int dist)
{
	// Base condition: leaf node
	if (adj[cur].size() == 1 && adj[cur][0].second == par)
	{
		if (maxDist < dist)
		{
			maxIdx = cur;
			maxDist = dist;
		}
		return;
	}

	// Traverse children
	for (auto& [weight, child] : adj[cur])
	{
		if (child == par) continue;
		dfs(child, cur, dist + weight);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int parent, child, cost;
		cin >> parent >> child >> cost;
		adj[parent].push_back({ cost,child });
		adj[child].push_back({ cost,parent });
	}

	// find A
	dfs(1,0,0);

	// find B
	maxDist = 0;
	dfs(maxIdx, 0, 0);

	cout << maxDist;
}
