#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <memory.h>
using namespace std;

bool visited[10000];
char commands[10000];
int prev_nums[10000];
int a, b;
string bfs();

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--)
	{
		cin >> a >> b;
		cout << bfs() << "\n";
	}

	return 0;
}


string bfs()
{
	memset(visited, 0, sizeof(visited));
	queue<int> to_visit;
	to_visit.push(a);

	while (!to_visit.empty())
	{
		int curr = to_visit.front();
		to_visit.pop();

		char options_c[4] = { 'D', 'S', 'L', 'R' };
		int options[4] = {
			(curr * 2) % 10000,
			curr == 0 ? 9999 : curr - 1,
			(curr % 1000) * 10 + curr / 1000,
			(curr % 10) * 1000 + curr / 10
		};

		for (int i = 0; i < 4; i++)
		{
			int next = options[i];
			if (next == b)
			{
				string ret = "";
				ret += options_c[i];
				while (curr != a)
				{
					ret = commands[curr] + ret;
					curr = prev_nums[curr];
				}
				return ret;
			}

			if (!visited[next])
			{
				prev_nums[next] = curr;
				commands[next] = options_c[i];
				visited[next] = true;
				to_visit.push(next);
			}
		}
	}
	return "";
}