#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define SPACE_PERSON 'P'
#define SPACE_WALL 'X'

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_rows, num_cols;
	cin >> num_rows >> num_cols;
	int origin_r = 0, origin_c = 0;

	vector<vector<char>> map(num_rows, vector<char>(num_cols));
	vector<vector<bool>> visited(num_rows, vector<bool>(num_cols));

	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			cin >> map[r][c];
			if (map[r][c] == 'I')
			{
				origin_r = r;
				origin_c = c;
			}
		}
	}

	// BFS algorithm
	int friends = 0;
	queue<pair<int, int>> to_visit;
	to_visit.push({ origin_r, origin_c });
	visited[origin_r][origin_c] = true;

	while (!to_visit.empty())
	{
		int curr_r = to_visit.front().first;
		int curr_c = to_visit.front().second;
		to_visit.pop();

		pair<int, int> neighbors[4] = { {curr_r + 1, curr_c}, {curr_r, curr_c + 1},
			{curr_r - 1, curr_c}, {curr_r, curr_c - 1 } };

		for (auto& pos : neighbors)
		{
			int r = pos.first;
			int c = pos.second;
			
			if (r < 0 || r >= num_rows || c < 0 || c >= num_cols 
				|| map[r][c] == SPACE_WALL || visited[r][c])
			{
				continue;
			}

			if (map[r][c] == SPACE_PERSON) friends++;
			visited[r][c] = true;
			to_visit.push({ r,c });
		}
	}
	
	if (friends == 0) cout << "TT" << "\n";
	else cout << friends << "\n";
}