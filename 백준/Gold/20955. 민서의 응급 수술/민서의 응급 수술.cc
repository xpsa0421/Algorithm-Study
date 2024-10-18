#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int parents[100001];

int find(int x)
{
	if (parents[x] == x) return x;
	return parents[x] = find(parents[x]);
}

bool merge(int x, int y)
{
	x = find(x); y = find(y);
	if (x == y) return false; // already the same tree
	parents[x] = y;
	return true; // just merged
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	// Initialisation
	for (int i = 1; i <= n; i++)
	{
		parents[i] = i;
	}
	
	// Edges
	int u, v;
	int numCuts = 0;
	while (m--)
	{
		cin >> u >> v;
		if (!merge(u, v)) numCuts++;
	}

	// Count the number of trees
	int numCons = -1;
	for (int i = 1; i <= n; i++)
	{
		if (parents[i] == i) numCons++;
	}

	cout << numCuts + numCons;
}
