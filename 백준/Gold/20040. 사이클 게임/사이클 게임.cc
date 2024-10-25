#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int p[500000];
bool added[500000];

int find(int a)
{
	if (p[a] < 0) return a;
	return p[a] = find(p[a]);
}

// 이미 같은 집합이면 false
bool merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return false;
	
	if (p[a] == p[b]) p[a]--;
	if (p[a] < p[b]) p[b] = a;
	else p[a] = b;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// Input
	int n, m;
	cin >> n >> m;

	// Solve
	fill(p, p + n, -1);
	int cycleIndex = 0;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;

		if (cycleIndex != 0) continue;
		bool isDiffGroup = merge(a, b);
		if (!isDiffGroup && added[a] && added[b])
			cycleIndex = i;
		added[a] = true, added[b] = true;
	}

	// Output
	cout << cycleIndex;
}
