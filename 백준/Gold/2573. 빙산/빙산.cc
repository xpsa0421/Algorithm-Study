#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int rows, cols;
	cin >> rows >> cols;
	vector<vector<int>> heights(rows, vector<int>(cols, 0));

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			cin >> heights[r][c];
		}
	}

	int years = 0;
	int num_groups = 1;
	do
	{
		vector<vector<bool>> visited(rows, vector<bool>(cols, false));
		queue<pair<int, int>> to_visit;
		bool all_melted = true;
		int num_groups = 0;

		for (int start_r = 0; start_r < rows; start_r++)
		{
			for (int start_c = 0; start_c < cols; start_c++)
			{
				if (heights[start_r][start_c] <= 0) continue;
				if (visited[start_r][start_c]) continue;
				all_melted = false;

				// end condition
				if (++num_groups > 1)
				{
					cout << years;
					return 0;
				}

				visited[start_r][start_c] = true;
				to_visit.push({ start_r, start_c });

				while (!to_visit.empty())
				{
					int r = to_visit.front().first;
					int c = to_visit.front().second;
					pair<int, int> nexts[4] = { {r - 1, c}, {r, c + 1}, {r + 1, c}, {r, c - 1} };
					to_visit.pop();

					for (auto& [next_r, next_c] : nexts)
					{
						if (0 > next_r || next_r >= rows || 0 > next_c || next_c >= cols) continue;
						if (visited[next_r][next_c]) continue;

						// check nearby ocean
						if (heights[next_r][next_c] <= 0)
						{
							heights[r][c]--;
						}
						else
						{
							to_visit.push({ next_r, next_c });
							visited[next_r][next_c] = true;
						}
					}
				}
			}
		}

		if (all_melted)
		{
			break;
		}
	} while (++years);

	cout << 0;
	return 0;
}