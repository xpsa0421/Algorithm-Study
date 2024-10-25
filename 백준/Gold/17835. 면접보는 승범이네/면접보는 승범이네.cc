#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> adj[100001]; // end, cost
vector<int> targets;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// Input
	int n, m, k;
	cin >> n >> m >> k;
	targets.resize(k);

	while (m--)
	{
		int u, v, c;
		cin >> u >> v >> c;
		adj[v].push_back({ u, c });
	}
	for (int i = 0; i < k; i++)
		cin >> targets[i];

	// Solve - Dijkstra
	const long long INF = 5000000000000001;
	vector<long long> minDists(n + 1, INF);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

	// 면접장들을 시작점으로 추가
	for (int i = 0; i < k; i++)
	{
		minDists[targets[i]] = 0;
		pq.push({ 0, targets[i] });
	}

	while (!pq.empty())
	{
		long long curC; int curV;
		tie(curC, curV) = pq.top(); pq.pop();
		if (minDists[curV] != curC) continue;

		for (auto& [nexV, nexC] : adj[curV])
		{
			long long newDist = minDists[curV] + nexC;
			if (minDists[nexV] <= newDist) continue;
			minDists[nexV] = newDist;
			pq.push({ minDists[nexV] , nexV });
		}
	}

	// 각 도시의 면접장까지의 거리
	long long farthest = 0;
	int farIdx = 0;
	for (int i = 1; i <= n; i++)
	{
		// 가장 먼 면접장까지의 거리 갱신
		if (farthest < minDists[i])
		{
			farIdx = i;
			farthest = minDists[i];
		}
	}

	// Output
	cout << farIdx << '\n' << farthest;
}
