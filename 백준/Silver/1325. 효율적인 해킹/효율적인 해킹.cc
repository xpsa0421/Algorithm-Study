#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<int> graph[10001];
bool visited[10001];
int counts[10001];
int maxCount = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		memset(visited, false, n + 1);
		queue<int> toVisit;
		toVisit.push(i);
		visited[i] = true;
		int cnt = 0;

		while (!toVisit.empty())
		{
			int cur = toVisit.front();
			toVisit.pop();
			
			for (int nxt : graph[cur])
			{
				if (visited[nxt]) continue;
				visited[nxt] = true;
				toVisit.push(nxt);
				cnt++;
			}
		}
		
		counts[i] = cnt;
		maxCount = max(cnt, maxCount);
	}

	for (int i = 1; i <= n; i++)
	{
		if (counts[i] == maxCount)
			cout << i << " ";
	}
}
