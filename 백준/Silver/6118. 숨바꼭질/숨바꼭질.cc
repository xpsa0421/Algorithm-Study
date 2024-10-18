#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int dist[20001];
bool visited[20001];
vector<int> adj[20001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int a, b;
	while (m--)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<int> toVisit;
	toVisit.push(1);
	visited[1] = true;
	int maxDist = 0;
	vector<int> maxDistPos;

	while (!toVisit.empty())
	{
		int cur = toVisit.front();
		toVisit.pop();

		for (int nxt : adj[cur])
		{
			if (visited[nxt]) continue;
			visited[nxt] = true;
			toVisit.push(nxt);
			dist[nxt] = dist[cur] + 1;

			if (maxDist < dist[nxt])
			{
				maxDist = dist[nxt];
				maxDistPos.clear();
				maxDistPos.push_back(nxt);
			}
			else if (maxDist == dist[nxt])
			{
				maxDistPos.push_back(nxt);
			}
		}
	}

	sort(maxDistPos.begin(), maxDistPos.end());
	cout << maxDistPos[0] << " " << maxDist << " " << maxDistPos.size();
}
