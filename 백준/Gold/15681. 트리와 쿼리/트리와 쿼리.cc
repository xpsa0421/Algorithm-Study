#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adj[100001];
bool visited[100001];
int numChildren[100001];

void dfs(int parent)
{
	numChildren[parent] = 1;
	for (int child : adj[parent])
	{
		if (visited[child]) continue;
		visited[child] = true;
		dfs(child);
		numChildren[parent] += numChildren[child];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, r, q;
	cin >> n >> r >> q;

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	visited[r] = true;
	dfs(r);

	while (q--)
	{
		int U;
		cin >> U;
		cout << numChildren[U] << '\n';
	}
}
