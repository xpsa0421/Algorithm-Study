#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define WALL '#'
#define EMPTY '.'
#define FIRE '*'
#define PLAYER '@'

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_tests = 0;
	cin >> num_tests;

	while (num_tests--)
	{
		// initialisation
		int rows = 0, cols = 0;
		cin >> cols >> rows;

		int start_r = 0, start_c = 0;
		vector<vector<char>> map(rows, vector<char>(cols, ' '));
		vector<vector<int>> fire_times(rows, vector<int>(cols, 10000));
		queue<pair<int, int>> to_visit;

		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < cols; c++)
			{
				cin >> map[r][c];
				if (map[r][c] == FIRE)
				{
					to_visit.emplace(r, c);
					fire_times[r][c] = 0;
				}
				else if (map[r][c] == PLAYER)
				{
					start_r = r; 
					start_c = c;
				}
			}
		}

		// solve
		// 모든 불 번지게 하기
		while (!to_visit.empty())
		{
			int fire_r = to_visit.front().first;
			int fire_c = to_visit.front().second;
			to_visit.pop();

			pair<int, int> neighbors[4] = {{fire_r - 1, fire_c}, {fire_r, fire_c - 1},
				{fire_r, fire_c + 1}, {fire_r + 1, fire_c}};

			for (auto [r, c] : neighbors)
			{
				if (r < 0 || r >= rows || c < 0 || c >= cols) continue;
				if (map[r][c] == EMPTY || map[r][c] == PLAYER)
				{
					fire_times[r][c] = fire_times[fire_r][fire_c] + 1;
					map[r][c] = FIRE;
					to_visit.emplace(r, c);
				}
			}
		}

		// 플레이어 이동시키기
		vector<vector<int>> player_times(rows, vector<int>(cols, -1));
		vector<vector<bool>> visited(rows, vector<bool>(cols, false));
		to_visit.emplace(start_r, start_c);
		player_times[start_r][start_c] = 0;
		visited[start_r][start_c] = true;
		int escape_time = -1;

		while (escape_time == -1 && !to_visit.empty())
		{
			int curr_r = to_visit.front().first;
			int curr_c = to_visit.front().second;
			to_visit.pop();

			pair<int, int> neighbors[4] = { {curr_r - 1, curr_c}, {curr_r, curr_c - 1},
				{curr_r, curr_c + 1}, {curr_r + 1, curr_c} };

			for (auto [r, c] : neighbors)
			{
				if (r < 0 || r >= rows || c < 0 || c >= cols)
				{
					escape_time = player_times[curr_r][curr_c] + 1;
					break;
				};

				if (visited[r][c] || map[r][c] == WALL) continue;
				if (fire_times[r][c] > player_times[curr_r][curr_c] + 1)
				{
					player_times[r][c] = player_times[curr_r][curr_c] + 1;
					visited[r][c] = true;
					to_visit.emplace(r, c);
				}
			}
		}
		
		if (escape_time == -1) cout << "IMPOSSIBLE\n";
		else cout << escape_time << "\n";
	}
}