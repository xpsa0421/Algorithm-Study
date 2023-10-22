#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_tests = 0;
	cin >> num_tests;
	pair<int, int> moves[8] = { {-1, -2}, {-2, -1}, {-2, 1}, {-1, +2}, {+1, +2}, {+2, +1}, {+2, -1}, {+1,-2} };
	
	while (num_tests--)
	{
		int size = 0;
		cin >> size;

		pair<int, int> start;
		cin >> start.first >> start.second;

		pair<int, int> end;
		cin >> end.first >> end.second;

		queue<pair<int, int>>to_visit;
		vector<vector<bool>> visited(size, vector<bool>(size, false));
		vector<vector<int>> counts(size, vector<int>(size, 0));
		to_visit.emplace(start);
		visited[start.first][start.second] = true;

		while (!to_visit.empty())
		{
			pair<int, int> curr = to_visit.front();
			to_visit.pop();
			if (curr == end)
			{
				break;
			}

			pair<int, int> next;
			for (auto [move_r, move_c] : moves)
			{
				next = { curr.first + move_r, curr.second + move_c };

				if (next.first < 0 || next.first >= size || next.second < 0 || next.second >= size) continue;
				if (visited[next.first][next.second]) continue;
				
				to_visit.push(next);
				visited[next.first][next.second] = true;
				counts[next.first][next.second] = counts[curr.first][curr.second] + 1;
			}
		}

		cout << counts[end.first][end.second] << "\n";
	}
}