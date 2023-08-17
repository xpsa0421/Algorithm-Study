#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 플로이드 워셜 알고리즘
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_vertices, num_nodes;
	cin >> num_vertices >> num_nodes;
	vector<vector<int>> connections(num_vertices + 1, vector<int>(num_vertices + 1, num_vertices + 1));

	for (int i = 1; i <= num_vertices; i++)
	{
		connections[i][i] = 0;
	}

	for (int i = 0; i < num_nodes; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		connections[a][b] = 1;
		connections[b][a] = 1;
	}

	for (int mid = 1; mid <= num_vertices; mid++)
	{
		for (int start = 1; start <= num_vertices; start++)
		{
			for (int end = 1; end <= num_vertices; end++)
			{
				connections[start][end] = min(connections[start][end], 
					connections[start][mid] + connections[mid][end]);
			}
		}
	}

	int min_index = 0;
	int min_score = num_vertices * num_vertices;
	for (int i = 1; i <= num_vertices; i++)
	{
		int score = 0;
		for (int j = 1; j <= num_vertices; j++)
		{
			score += connections[i][j];
		}
		if (min_score > score)
		{
			min_score = score;
			min_index = i;
		}		
	}
	
	cout << min_index;
}