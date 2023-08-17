#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& connections, vector<bool>& visited, int start_idx);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int vertex_count, linkage_count;
	cin >> vertex_count >> linkage_count;

	vector<vector<int>> connections(vertex_count + 1);
	vector<bool> visited(vertex_count + 1);

	while (linkage_count--)
	{
		int u, v;
		cin >> u >> v;

		connections[u].push_back(v);
		connections[v].push_back(u);
	}

	int count = 0;
	for (int i = 1; i < vertex_count + 1; i++)
	{
		if (visited[i]) continue;

		count++;
		BFS(connections, visited, i);
	}

	cout << count << "\n";
}

void BFS(vector<vector<int>>& connections, vector<bool>& visited, int start_idx)
{
	queue<int> to_visit;
	to_visit.push(start_idx);
	visited[start_idx] = true;

	while (!to_visit.empty())
	{
		int curr_idx = to_visit.front();
		to_visit.pop();

		for (auto& connected_idx : connections[curr_idx])
		{
			if (!visited[connected_idx])
			{
				to_visit.push(connected_idx);
				visited[connected_idx] = true;
			}
		}
	}
}