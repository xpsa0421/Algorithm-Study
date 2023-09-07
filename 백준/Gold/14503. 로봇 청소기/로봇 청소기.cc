#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define NOT_CLEANED 0
#define WALL 1
#define CLEANED 2
#define DIR_NORTH 0
#define DIR_EAST 1
#define DIR_SOUTH 2
#define DIR_WEST 3

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int rows, cols, start_r, start_c, start_dir;
	cin >> rows >> cols >> start_r >> start_c >> start_dir;
	vector<vector<int>> map(rows, vector<int>(cols, 0));

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			cin >> map[r][c];
		}
	}

	int num_cleaned = 0;
	int r = start_r;
	int c = start_c;
	int dir = start_dir;
	bool operating = true;

	while (operating)
	{
		if (map[r][c] == NOT_CLEANED)
		{
			map[r][c] = CLEANED;
			num_cleaned++;
		}

		bool has_nearby_clean = false;
		pair<int, int> nexts[4] = { {r - 1, c}, {r, c + 1}, {r + 1, c}, {r, c - 1} };
		for (auto& [next_r, next_c] : nexts)
		{
			if (next_r < 0 || next_r >= rows || next_c < 0 || next_c >= cols) continue;
			if (map[next_r][next_c] == NOT_CLEANED)
			{
				has_nearby_clean = true;
				break;
			}
		}

		if (has_nearby_clean)
		{
			dir -= 1;
			if (dir == -1) dir = 3;

			if (map[nexts[dir].first][nexts[dir].second] == NOT_CLEANED)
			{
				r = nexts[dir].first;
				c = nexts[dir].second;
			}
		}
		else
		{
			int back = dir + 2;
			if (back >= 4) back -= 4;
			
			if (map[nexts[back].first][nexts[back].second] == WALL)
			{
				operating = false;
			}
			else
			{
				r = nexts[back].first;
				c = nexts[back].second;
			}
		}
	}

	cout << num_cleaned;
}