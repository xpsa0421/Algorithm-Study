#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n = 0;
char map[6][6];
vector<pair<int, int>> teachers;
vector<pair<int, int>> empties;

bool Check()
{
	bool hidden = true; 
	for (auto [teac_r, teac_c] : teachers)
	{
		if (!hidden) break;

		// left
		for (int c = teac_c - 1; c >= 0; c--)
		{
			if (map[teac_r][c] == 'O') break;
			if (map[teac_r][c] == 'S')
			{
				hidden = false;
				break;
			}
		}

		// right
		if (!hidden) break;
		for (int c = teac_c + 1; c < n; c++)
		{
			if (map[teac_r][c] == 'O') break;
			if (map[teac_r][c] == 'S')
			{
				hidden = false;
				break;
			}
		}

		// top
		if (!hidden) break;
		for (int r = teac_r - 1; r >= 0; r--)
		{
			if (map[r][teac_c] == 'O') break;
			if (map[r][teac_c] == 'S')
			{
				hidden = false;
				break;
			}
		}

		// bottom
		if (!hidden) break;
		for (int r = teac_r + 1; r < n; r++)
		{
			if (map[r][teac_c] == 'O') break;
			if (map[r][teac_c] == 'S')
			{
				hidden = false;
				break;
			}
		}
	}
	return hidden;
}

void DFS(int idx, int depth = 0)
{
	if (depth == 3)
	{
		if (Check())
		{
			cout << "YES";
			exit(0);
		};
		return;
	}

	for (int i = idx; i < empties.size(); i++)
	{
		map[empties[i].first][empties[i].second] = 'O';
		DFS(i + 1, depth + 1);
		map[empties[i].first][empties[i].second] = 'X';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	cin >> n;

	int teacher_r = 0, teacher_c = 0;
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			cin >> map[r][c];
			if (map[r][c] == 'T') teachers.emplace_back(r, c);
			else if (map[r][c] == 'X') empties.emplace_back(r, c);
		}
	}
	
	// solve
	DFS(0, 0);

	// output
	cout << "NO";
}
