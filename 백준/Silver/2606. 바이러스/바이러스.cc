#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>&, vector<bool>&, int n, int& count);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> connections(n + 1);
	vector<bool> visited(n, false);

	while (m--)
	{
		int comp_a, comp_b;
		cin >> comp_a >> comp_b;
		connections[comp_a].push_back(comp_b);
		connections[comp_b].push_back(comp_a);
	}

	int count = -1;
	DFS(connections, visited, 1, count);

	cout << count;
}

void DFS(vector<vector<int>>& connections, vector<bool>& visited, int n, int& count)
{
	count++;
	visited[n] = true;

	for (auto& connected_idx : connections[n])
	{
		if (visited[connected_idx])
			continue;

		DFS(connections, visited, connected_idx, count);
	}
}
