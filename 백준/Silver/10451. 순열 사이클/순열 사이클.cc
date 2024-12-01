#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

int adj[1001];
bool visited[1001];
int start;

bool dfs(int c)
{
	if (visited[c])
	{
		if (start == c) return true;
		return false;
	}
	visited[c] = true;
	return dfs(adj[c]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		fill(visited, visited + n + 1, false);
		for (int i = 1; i <= n; i++)
			cin >> adj[i];
		
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (visited[i]) continue;
			start = i;
			if (dfs(i)) cnt++;
		}
		cout << cnt << '\n';
	}
}