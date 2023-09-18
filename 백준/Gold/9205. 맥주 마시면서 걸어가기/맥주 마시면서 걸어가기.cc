#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool IsReachable(pair<int,int> start, pair<int,int> end)
{
	return (abs(end.first - start.first) + abs(end.second - start.second) <= 1000);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_tests = 0;
	cin >> num_tests;

	while (num_tests--)
	{
		// initialisation
		int num_stores = 0, start_x = 0, start_y = 0, end_x = 0, end_y = 0;
		cin >> num_stores >> start_x >> start_y;
		vector<pair<int, int>> nodes = { {start_x, start_y} };

		for (int i = 0; i < num_stores; i++)
		{
			int x = 0, y = 0;
			cin >> x >> y;
			nodes.push_back({x, y});
		}

		cin >> end_x >> end_y;
		nodes.push_back({ end_x, end_y });
		vector<vector<int>> neighbors(num_stores + 2);

		// solve
		for (int i = 0; i < nodes.size(); i++)
		{
			for (int j = i + 1; j < nodes.size(); j++)
			{
				if (IsReachable(nodes[i], nodes[j]))
				{
					neighbors[i].push_back(j);
					neighbors[j].push_back(i);
				}
			}
		}

		// bfs
		queue<int> to_visit;
		vector<bool> visited(num_stores + 2, false);
		to_visit.emplace(0);
		visited[0] = true;

		while (!to_visit.empty())
		{
			int curr = to_visit.front();
			to_visit.pop();
			
			for (int neighbor : neighbors[curr])
			{
				if (visited[neighbor]) continue;
				visited[neighbor] = true;
				to_visit.push(neighbor);
			}
		}

		// output
		cout << (visited[num_stores + 1] ? "happy\n" : "sad\n");
	}
}