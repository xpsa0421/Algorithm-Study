#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> heights(n, vector<int>(n, 0));
	int max_area_count = 1;
	int max_height = 0;

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			cin >> heights[r][c];
			max_height = max(max_height, heights[r][c]);
		}
	}

	for (int drown_height = 1; drown_height < max_height; drown_height++)
	{
		int area_count = 0;
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		queue<pair<int, int>> to_visit;

		for (int start_r = 0; start_r < n; start_r++)
		{
			for (int start_c = 0; start_c < n; start_c++)
			{
				if (visited[start_r][start_c]) continue;
				if (heights[start_r][start_c] <= drown_height) continue;

				area_count++;
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
						if (0 > next_r || next_r >= n || 0 > next_c || next_c >= n) continue;
						if (visited[next_r][next_c]) continue;
						if (heights[next_r][next_c] <= drown_height) continue;

						to_visit.push({ next_r, next_c });
						visited[next_r][next_c] = true;
					}
				}
			}
		}
		
		max_area_count = max(area_count, max_area_count);
	}

	cout << max_area_count;
	return 0;
}