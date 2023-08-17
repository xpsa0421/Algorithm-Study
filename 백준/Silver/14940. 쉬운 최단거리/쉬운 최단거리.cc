#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_rows, num_cols;
	cin >> num_rows >> num_cols;

	vector<vector<int>> map(num_rows, vector<int>(num_cols, 0));
	vector<vector<int>> distance(num_rows, vector<int>(num_cols, 0));
	vector<vector<bool>> visited(num_rows, vector<bool>(num_cols, false));
	queue<pair<int, int>> to_visit;

	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			cin >> map[r][c];
			if (map[r][c] == 2) to_visit.push(make_pair(r, c));
			else if (map[r][c] == 1) distance[r][c] = -1;
		}
	}

	// 목표지점에서 출발해서 각 위치까지의 distance 구하기 BFS
	visited[to_visit.front().first][to_visit.front().second] = true;

	while (!to_visit.empty())
	{
		int r = to_visit.front().first;
		int c = to_visit.front().second;
		to_visit.pop();

		pair<int, int> can_visit[4] = { {r - 1, c}, {r, c + 1}, {r + 1, c}, {r, c - 1} };
		for (auto& near : can_visit)
		{
			int new_r = near.first;
			int new_c = near.second;

			if (0 <= new_r && new_r < num_rows
				&& 0 <= new_c && new_c < num_cols
				&& !visited[new_r][new_c]
				&& map[new_r][new_c] != 0)
			{
				to_visit.push({ new_r, new_c });
				visited[new_r][new_c] = true;
				distance[new_r][new_c] = distance[r][c] + 1;
			}
		}
	}

	// print
	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			cout << distance[r][c] << " ";
		}
		cout << "\n";
	}
}
