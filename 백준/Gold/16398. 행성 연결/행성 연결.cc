#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

vector<tuple<int, int, int>> edges; // cost, ori, dst
vector<int> parents(1001, -1);

int find(int x)
{
	if (parents[x] < 0) return x;
	else return parents[x] = find(parents[x]);
}

bool merge(int x, int y)
{
	x = find(x); y = find(y);
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

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int cost; cin >> cost;
			if (i >= j) continue;
			edges.push_back({ cost, i, j });
		}
	}
	sort(edges.begin(), edges.end());

	int cnt = 0;
	long long ans = 0;
	for (auto&[cost, ori, dst] : edges)
	{
		if (!merge(ori,dst)) continue;
		ans += cost; cnt++;
		if (cnt == n - 1) break;
	}

	cout << ans << '\n';
}
