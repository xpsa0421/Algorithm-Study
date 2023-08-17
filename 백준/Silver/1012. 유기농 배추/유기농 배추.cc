#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

void BFS(int start_x, int start_y, int length, int height);

bool planted[50][50];
bool visited[50][50];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int t, m, n, k;
	cin >> t;
	
	vector<pair<int, int>> planted_pos;	
	
	while (t--)
	{
		memset(planted, 0, sizeof(planted));
		memset(visited, 0, sizeof(planted));
		planted_pos.clear();

		cin >> m >> n >> k;

		while (k--)
		{
			int x, y;
			cin >> x >> y;

			planted[x][y] = true;
			planted_pos.push_back(make_pair(x, y));
		}

		int worm_count = 0;
		for (auto& cabbage : planted_pos)
		{
			if (!visited[cabbage.first][cabbage.second])
			{
				worm_count++;
				BFS(cabbage.first, cabbage.second, m, n);
			}
		}

		cout << worm_count << "\n";
	}	
}

void BFS(int start_x, int start_y, int length, int height)
{
	queue<pair<int, int>> to_visit;
	to_visit.push(make_pair(start_x, start_y));

	while (!to_visit.empty())
	{
		int x = to_visit.front().first;
		int y = to_visit.front().second;

		to_visit.pop();
		if (visited[x][y]) continue;

		visited[x][y] = true;		
	
		// left
		if (x != 0)
		{
			if (planted[x - 1][y]) to_visit.push(make_pair(x - 1, y));
		}
		// right
		if (x != length - 1)
		{
			if (planted[x + 1][y]) to_visit.push(make_pair(x + 1, y));
		}
		// top
		if (y != 0)
		{
			if (planted[x][y - 1]) to_visit.push(make_pair(x, y - 1));
		}
		// bottom
		if (y != height - 1)
		{
			if (planted[x][y + 1]) to_visit.push(make_pair(x, y + 1));
		}
	}
}
