#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> tree[1001]; // idx, distance
int dist[1001];
bool visited[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n - 1; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		tree[u].push_back({ v,d });
		tree[v].push_back({ u,d });
	}

	while (m--)
	{
		int u, v;
		cin >> u >> v;

		memset(visited, false, sizeof(visited));
		memset(dist, 0, sizeof(dist));
		queue<int> toVisit;
		toVisit.push(u);
		visited[u] = true;

		while (!toVisit.empty())
		{
			int cur = toVisit.front();
			toVisit.pop();

			for (auto& [nxt, distance] : tree[cur])
			{
				if (visited[nxt]) continue;
				visited[nxt] = true;
				dist[nxt] = dist[cur] + distance;
				toVisit.push(nxt);

				if (nxt == v)
				{
					while (!toVisit.empty()) toVisit.pop();
					break;
				}
			}
		}

		cout << dist[v] << '\n';
	}
}
