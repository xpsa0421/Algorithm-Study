#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[1001];
int inDegrees[1001];
queue<int> readyQ;
vector<int> res;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;
	while (m--)
	{
		int numSingers; cin >> numSingers;
		int prev = 0; int cur = 0;
		while (numSingers--)
		{
			cin >> cur;
			if (prev != 0)
			{
				adj[prev].push_back(cur);
				inDegrees[cur]++;
			}
			prev = cur;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (inDegrees[i] == 0) readyQ.push(i);
	}

	while (!readyQ.empty())
	{
		int cur = readyQ.front(); readyQ.pop();
		res.push_back(cur);

		for (int nxt : adj[cur])
		{
			inDegrees[nxt]--;
			if (inDegrees[nxt] == 0) readyQ.push(nxt);
		}
	}

	if (res.size() != n)
	{
		cout << 0;
	}
	else
	{
		for (int nxt : res)
			cout << nxt << "\n";
	}
}
