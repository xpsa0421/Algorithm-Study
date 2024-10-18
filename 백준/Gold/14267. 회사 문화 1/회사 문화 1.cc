#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int scores[100001];
vector<int> adj[100001];

void dfs(int cur)
{
	for (int nxt : adj[cur])
	{
		scores[nxt] += scores[cur];
		dfs(nxt);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;
	
	// 사장
	int boss; cin >> boss;

	// 직원
	for (int i = 2; i <= n; i++)
	{
		cin >> boss;
		adj[boss].push_back(i);
	}

	while (m--)
	{
		int i, w;
		cin >> i >> w;
		scores[i] += w;
	}

	dfs(1);

	for (int i = 1; i <= n; i++)
		cout << scores[i] << ' ';
}
