#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<tuple<int, int, int>> edges;
vector<int> parents(100001, -1);

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

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c,a,b });
	}
	sort(edges.begin(), edges.end());

	int cnt = 0, totalCost = 0;
	for (auto& [cost, ori, dst] : edges)
	{
		if (cnt == n - 2) break;
		if (!merge(ori, dst)) continue;
		totalCost += cost;
		cnt++;
	}

	cout << totalCost;
}
