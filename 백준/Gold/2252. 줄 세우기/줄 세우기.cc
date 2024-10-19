#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[32001];
int inDegrees[32001];
vector<int> res;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;
	int a, b;
	while (m--)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		inDegrees[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (inDegrees[i] == 0) q.push(i);
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		res.push_back(cur);
		
		for (int con : adj[cur])
		{
			if (--inDegrees[con] == 0)
				q.push(con);
		}
	}

	for (int r : res)
		cout << r << " ";
}
