#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

vector<vector<int>> friends;
vector<bool> visited;
int n, m;

bool dfs(int c, int depth)
{
	if (depth == 4) return true;
	visited[c] = true;

	for (int f : friends[c])
	{
		if (visited[f]) continue;
		if (dfs(f, depth + 1)) return true;
		else visited[f] = false;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;
	friends.resize(n);
	visited.resize(n, false);
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		if (dfs(i, 0))
		{
			cout << 1;
			return 0;
		}
		fill(visited.begin(), visited.end(), false);
	}
	cout << 0;
}