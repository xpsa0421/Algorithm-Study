#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int rows = 0, cols = 0, num_squares = 0;
	cin >> rows >> cols >> num_squares;

	vector<vector<bool>> filled(rows, vector<bool>(cols, false));
	while (num_squares--)
	{
		int bottomleft_r = 0, bottomleft_c = 0, topright_r = 0, topright_c = 0;
		cin >> bottomleft_c >> bottomleft_r >> topright_c >> topright_r;

		for (int r = bottomleft_r; r < topright_r; r++)
		{
			for (int c = bottomleft_c; c < topright_c; c++)
			{
				filled[r][c] = true;
			}
		}
	}	

	// solve
	int num_areas = 0;
	vector<int> areas;
	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
	queue<pair<int, int>> to_visit;

	for (int start_r = 0; start_r < rows; start_r++)
	{
		for (int start_c = 0; start_c < cols; start_c++)
		{
			if (!visited[start_r][start_c] && !filled[start_r][start_c])
			{
				int curr_area = 0;
				num_areas++;
				to_visit.emplace(start_r, start_c);
				visited[start_r][start_c] = true;

				// BFS
				while (!to_visit.empty())
				{
					curr_area++;
					int r = to_visit.front().first;
					int c = to_visit.front().second;
					to_visit.pop();

					pair<int, int> neighbors[4] = { {r - 1, c}, {r, c + 1}, {r + 1, c}, {r, c - 1} };
					for (auto [next_r, next_c] : neighbors)
					{
						if (next_r < 0 || next_r == rows || next_c < 0 || next_c == cols) continue;
						if (visited[next_r][next_c]) continue;

						if (!filled[next_r][next_c])
						{
							to_visit.emplace(next_r, next_c);
							visited[next_r][next_c] = true;
						}
					}
				}

				areas.push_back(curr_area);
			}
		}
	}
	
	// output
	cout << num_areas << "\n";
	sort(areas.begin(), areas.end());
	for (int area : areas)
	{
		cout << area << " ";
	}
}
