#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<tuple<int, int, int>> edges;
vector<int> parents(1001, -1);

int find(int x)
{
	if (parents[x] < 0) return x;
	else return parents[x] = find(parents[x]);
}

bool merge(int x, int y)
{
	x = find(x), y = find(y);
	if (x == y) return false;
	
	if (parents[x] == parents[y]) parents[x]--;
	if (parents[x] < parents[y]) parents[y] = x;
	else parents[x] = y;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	m++; n++;
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ 1 - c, a, b }); // 오르막길 1 내리막길 0
	}

	// 최악의 코스
	sort(edges.begin(), edges.end(), greater<tuple<int,int,int>>());
	int maxNumUps = 0, cnt = 0;
	for (auto& [c, a, b] : edges)
	{
		if (!merge(a, b)) continue;
		maxNumUps += c;
		cnt++;
		if (cnt == n - 1) break;
	}

	// 최선의 코스
	fill(parents.begin(), parents.begin() + n + 1, -1);
	sort(edges.begin(), edges.end());
	int minNumUps = 0; cnt = 0;
	for (auto& [c, a, b] : edges)
	{
		if (!merge(a, b)) continue;
		minNumUps += c;
		cnt++;
		if (cnt == n - 1) break;
	}

	cout << maxNumUps * maxNumUps - minNumUps * minNumUps;
}
