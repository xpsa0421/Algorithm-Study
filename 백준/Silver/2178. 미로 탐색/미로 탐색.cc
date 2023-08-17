#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_rows, num_cols;
	cin >> num_rows >> num_cols;

	vector<string> can_go(num_rows);
	vector<vector<bool>> visited(num_rows, vector<bool>(num_cols, false));
	vector<vector<int>> distance(num_rows, vector<int>(num_cols, 0));
	
	for (int i = 0; i < num_rows; i++)
	{
		cin >> can_go[i];
	}

	// BFS
	queue<pair<int,int>> to_visit;
	to_visit.push({ 0,0 });
	visited[0][0] = true;
	distance[0][0] = 1;

	while (!to_visit.empty())
	{
		pair<int, int> curr = to_visit.front();
		pair<int, int> neighbors[4] = { {curr.first - 1, curr.second}, {curr.first, curr.second - 1},
			{curr.first, curr.second + 1}, { curr.first + 1, curr.second } };
		to_visit.pop();

		for (auto&[r, c] : neighbors)
		{
			if (r < 0 || r >= num_rows || c < 0 || c >= num_cols)
				continue;

			if (can_go[r][c] == '1' && !visited[r][c])
			{
				visited[r][c] = true;
				distance[r][c] = distance[curr.first][curr.second] + 1;
				to_visit.push({ r,c });
			}
		}
	}
	
	cout << distance[num_rows - 1][num_cols - 1];
}