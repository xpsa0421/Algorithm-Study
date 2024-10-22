#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
#define MAX 0x7f7f7f7f

vector<vector<pair<int, int>>> adj;
int maxIdx; int maxDist;

void findFarthest(int start, int runDist, int prev)
{
	// base condition: leaf
	if (adj[start].size() == 1 && adj[start][0].first == prev)
	{
		if (maxDist < runDist)
		{
			maxIdx = start;
			maxDist = runDist;
			return;
		}
	}

	// traverse
	for (auto& [nextV, nextC] : adj[start])
	{
		if (nextV == prev) continue;
		findFarthest(nextV, runDist + nextC, start);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int v; cin >> v;
	adj.resize(v + 1);
	for (int i = 0; i < v; i++)
	{
		int st; cin >> st;
		while (true)
		{
			int en, dist;
			cin >> en; if (en == -1) break;
			cin >> dist;
			adj[st].push_back({ en, dist });
		}
	}

	findFarthest(1, 0, 0);
	int a = maxIdx;

	findFarthest(a, 0, 0);
	cout << maxDist;	
}
