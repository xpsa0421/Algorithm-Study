#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int rows = 0, cols = 0;
	cin >> rows >> cols;

	vector<vector<int>> painting(rows, vector<int>(cols, 0));
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			cin >> painting[r][c];
		}
	}

	int num_paintings = 0;
	int max_size = 0;
	vector<vector<bool>> visited(rows, vector<bool>(cols, false));

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			if (painting[r][c] == 1 && !visited[r][c])
			{
				queue<pair<int, int>> to_visit;
				to_visit.push({ r, c });
				visited[r][c] = true;
				int size = 1;
				num_paintings++;

				while (!to_visit.empty())
				{
					int r = to_visit.front().first;
					int c = to_visit.front().second;
					to_visit.pop();

					pair<int, int> neighbors[4] = { {r - 1,c}, {r + 1, c}, {r, c - 1}, {r, c + 1} };
					for (auto& [next_r, next_c] : neighbors)
					{
						if (next_r < 0 || next_r >= rows || next_c < 0 || next_c >= cols) continue;
						if (visited[next_r][next_c]) continue;
						if (!painting[next_r][next_c]) continue;

						size++;
						visited[next_r][next_c] = true;
						to_visit.push({ next_r, next_c });
					}
				}
				
				max_size = max(max_size, size);
			}
		}
	}
	
	cout << num_paintings << " " << max_size;
}