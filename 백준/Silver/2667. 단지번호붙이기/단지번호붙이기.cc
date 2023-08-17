#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string map[25];
bool visited[25][25] = {};
int n = 0;

int DFS(int r, int c);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}

	vector<int> villages;
	int village_count = 0;

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			if (map[r][c] == '0') continue;
			if (!visited[r][c])
			{
				village_count++;
				villages.push_back(DFS(r, c));
			}
		}
	}
	sort(villages.begin(), villages.end());

	cout << village_count << "\n";
	for (auto& count : villages)
		cout << count << "\n";
}

int DFS(int r, int c)
{
	int count = 1;
	visited[r][c] = true;

	pair<int, int> neighbors[4] = { {r - 1, c}, {r, c - 1},	{r, c + 1}, { r + 1, c } };

	for (auto& [next_r, next_c] : neighbors)
	{
		if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= n)
			continue;

		if (map[next_r][next_c] == '1' && !visited[next_r][next_c])
		{
			count += DFS(next_r, next_c);
		}
	}

	return count;
}