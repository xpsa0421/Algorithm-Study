#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> parents(1000, -1);
vector<tuple<int, int, int>> edges;

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
		int c; cin >> c;
		edges.push_back({ c, i, 0 });
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int c; cin >> c;
			if (i >= j) continue;
			edges.push_back({ c,i,j });
		}
	}

	n++;
	sort(edges.begin(), edges.end());
	int cnt = 0, ans = 0;

	for (int i = 0; i < edges.size(); i++)
	{
		int a, b, c;
		tie(c, a, b) = edges[i];
		if (!merge(a, b)) continue;

		ans += c;
		if (++cnt == n - 1) break;
	}

	cout << ans;
}
