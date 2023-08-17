#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
string painting[100];
vector<vector<bool>> visited(100, vector<bool>(100, false));
vector<vector<bool>> visited_cow(100, vector<bool>(100, false));
void DFS(int i, int j);
void DFS_Cow(int i, int j);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> painting[i];
	}

	int regions = 0, regions_cow = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				regions++;
				DFS(i, j);
			}
			if (!visited_cow[i][j])
			{
				regions_cow++;
				DFS_Cow(i, j);
			}
		}
	}
	
	cout << regions << " " << regions_cow;
}

void DFS(int i, int j) 
{
	visited[i][j] = true;

	pair<int, int> neighbors[4] = {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
	for (auto& [r, c] : neighbors)
	{
		if (0 <= r && r < n && 0 <= c && c < n && !visited[r][c])
		{
			if (painting[i][j] == painting[r][c])
				DFS(r, c);
		}
	}
}

void DFS_Cow(int i, int j)
{
	visited_cow[i][j] = true;

	pair<int, int> neighbors[4] = { {i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1} };
	for (auto& [r, c] : neighbors)
	{
		if (0 <= r && r < n && 0 <= c && c < n && !visited_cow[r][c])
		{
			if (painting[i][j] == 'R' && painting[r][c] == 'G' ||
				painting[i][j] == 'G' && painting[r][c] == 'R' ||
				painting[i][j] == painting[r][c])
			DFS_Cow(r, c);
		}
	}
}