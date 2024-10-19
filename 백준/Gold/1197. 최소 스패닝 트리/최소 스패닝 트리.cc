#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int v, e;
vector<tuple<int, int, int>> edges; // cost, a, b
int roots[10001];

void init(int n)
{
	for (int i = 1; i <= n; i++)
		roots[i] = i;
}

int find(int x)
{
	if (roots[x] == x) return x;
	return roots[x] = find(roots[x]);
}

bool merge(int x, int y)
{
	x = find(x); y = find(y);
	if (x == y) return false;
	if (y < x) swap(x, y);
	roots[y] = x;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> v >> e;
	while (e--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c,a,b });
	}

	sort(edges.begin(), edges.end());
	
	init(v);
	int cnt = 0, ans = 0;
	for (auto& [c, a, b] : edges)
	{
		if (!merge(a, b)) continue;
		cnt++; ans += c;
		if (cnt == v - 1) break;
	}

	cout << ans;
}
