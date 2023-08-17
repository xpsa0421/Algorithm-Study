#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int num_conn;
vector<int> order_BFS;
vector<int> order_DFS;
vector<vector<int>> connections(1001);
vector<bool> visited_BFS(1001, false);
vector<bool> visited_DFS(1001, false);

void DFS(int n);
void BFS(int n);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_indices, start_idx;
	cin >> num_indices >> num_conn >> start_idx;

	for (int i = 0; i < num_conn; i++)
	{
		int start, end;
		cin >> start >> end;

		connections[start].push_back(end);
		connections[end].push_back(start);
	}
	for (int i = 1; i <= num_indices; i++)
	{
		sort(connections[i].begin(), connections[i].end());
	}

	DFS(start_idx);	
	BFS(start_idx);


	for (int& index : order_DFS)
	{
		cout << index << " ";
	}
	cout << "\n";
	for (int& index : order_BFS)
	{
		cout << index << " ";
	}
}

void DFS(int n)
{
	order_DFS.push_back(n);
	visited_DFS[n] = true;

	for (auto& neighbor : connections[n])
	{
		if (!visited_DFS[neighbor])
		{
			DFS(neighbor);
		}
	}
}

void BFS(int n)
{
	queue<int> to_visit;
	to_visit.push(n);
	visited_BFS[n] = true;
	order_BFS.push_back(n);

	while (!to_visit.empty())
	{
		int curr = to_visit.front();
		to_visit.pop();

		for (auto& neighbor : connections[curr])
		{
			if (!visited_BFS[neighbor])
			{
				visited_BFS[neighbor] = true;
				to_visit.push(neighbor);
				order_BFS.push_back(neighbor);
			}
		}
	}
}