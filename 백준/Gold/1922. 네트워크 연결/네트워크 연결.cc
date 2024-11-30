#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

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
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<tuple<int, int, int>> pq; // cost, a, b
	while (m--)
	{
		int c, a, b;
		cin >> a >> b >> c;
		pq.push_back({ c, a, b });
	}
	sort(pq.begin(), pq.end());

	int total = 0;
	int link = 0;
	for (auto& [c, a, b] : pq)
	{
		if (!merge(a, b)) continue;
		total += c;
		link++;
		if (link == n - 1) break;
	}

	cout << total;
}