#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adj[501];
int parents[501];
bool visited[501];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	int testNo = 1;
	while (n != 0 || m != 0)
	{
		fill(begin(adj), end(adj), vector<int>());
		memset(visited, false, sizeof(visited));

		int a, b;
		while (m--)
		{
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		int numTrees = 0;
		queue<int> toVisit;
		for (int i = 1; i <= n; i++)
		{
			if (visited[i]) continue;
			visited[i] = true;
			parents[i] = 0;
			toVisit.push(i);

			bool hasCycle = false;
			while (!toVisit.empty())
			{
				int cur = toVisit.front();
				toVisit.pop();

				for (int nxt : adj[cur])
				{
					if (visited[nxt])
					{
						if (nxt != parents[cur]) hasCycle = true;
						continue;
					}
					visited[nxt] = true;
					parents[nxt] = cur;
					toVisit.push(nxt);
				}
			}
			if (!hasCycle) numTrees++;
		}

		std::cout << "Case " << testNo << ": ";
		switch (numTrees)
		{
		case 0:
			std::cout << "No trees.\n";
			break;

		case 1:
			std::cout << "There is one tree.\n";
			break;

		default:
			std::cout << "A forest of " << numTrees << " trees.\n";
			break;
		}

		cin >> n >> m;
		testNo++;
	}
}
