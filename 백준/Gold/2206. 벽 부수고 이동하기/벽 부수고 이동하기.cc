#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int rows = 0, cols = 0;
	cin >> rows >> cols;
	vector<vector<bool>> is_wall(rows, vector<bool>(cols, false));
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			char wall_c = ' ';
			cin >> wall_c;
			is_wall[r][c] = wall_c == '0' ? 0 : 1;
		}
	}

	// solve
	vector<vector<vector<int>>> distance(2, (vector<vector<int>>(rows, vector<int>(cols, -1))));
	queue<tuple<int, int, int>> to_visit;
	to_visit.push(make_tuple(0,0,0)); // starting position
	distance[0][0][0] = 1;

	int curr_r = 0, curr_c = 0, is_broken = 0;
	while (!to_visit.empty())
	{
		tie(curr_r, curr_c, is_broken) = to_visit.front();
		to_visit.pop();

		if (curr_r == rows - 1 && curr_c == cols - 1)
		{
			cout << distance[is_broken][curr_r][curr_c];
			return 0;
		}

		pair<int, int> neighbors[4] = { {curr_r, curr_c - 1}, {curr_r, curr_c + 1}, {curr_r - 1, curr_c}, {curr_r + 1, curr_c} };
		for (auto [r, c] : neighbors)
		{
			if (r < 0 || r >= rows || c < 0 || c >= cols) continue;

			if (!is_wall[r][c])
			{
				if (distance[is_broken][r][c] == -1)
				{
					to_visit.emplace(r, c, is_broken);
					distance[is_broken][r][c] = distance[is_broken][curr_r][curr_c] + 1;
				}
			}
			else if (!is_broken && distance[1][r][c] == -1)
			{
				to_visit.emplace(r, c, 1);
				distance[1][r][c] = distance[is_broken][curr_r][curr_c] + 1;
			}
		}
	}

	cout << -1;
}
