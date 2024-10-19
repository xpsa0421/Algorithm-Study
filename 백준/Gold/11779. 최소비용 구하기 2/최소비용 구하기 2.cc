#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
#define INF 1e9+10

vector<pair<int, int>> edges[1001]; // cost, nxt
int minCosts[1001];
int pre[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ c,b });
	}

	int start, end;
	cin >> start >> end;

	// Dijkstra
	fill(minCosts, minCosts + n + 1, INF); minCosts[start] = 0;
	priority_queue<pair<int, int>> pq; // cost, vertex
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int curC, curV;
		tie(curC, curV) = pq.top(); pq.pop();

		if (minCosts[curV] != curC) continue;
		for (auto& [nxtC, nxtV] : edges[curV])
		{
			if (minCosts[nxtV] > minCosts[curV] + nxtC)
			{
				minCosts[nxtV] = minCosts[curV] + nxtC;
				pre[nxtV] = curV;
				pq.push({ minCosts[nxtV], nxtV });
			}
		}
	}

	// Cost
	cout << minCosts[end] << '\n';

	// Path
	int cur = end;
	stack<int> path;
	path.push(end);
	while (cur != start)
	{
		path.push(pre[cur]);
		cur = pre[cur];
	}

	// Print
	cout << path.size() << '\n';
	while (!path.empty())
	{
		cout << path.top() << ' ';
		path.pop();
	}
}
