#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

void BFS(int n, int k);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	BFS(n, k);
}

void BFS(int n, int k)
{
	queue<int> to_visit;
	bool visited[100001];
	int time[100001];
	memset(visited, 0, sizeof(visited));
	memset(time, 0, sizeof(time));

	to_visit.push(n);
	visited[n] = true;

	while (!to_visit.empty())
	{
		int x = to_visit.front();
		to_visit.pop();
		if (x == k) break;

		int check_idx[3] = { x * 2, x - 1, x + 1 };
		for (int i = 0; i < 3; i++)
		{
			if (0 <= check_idx[i] && check_idx[i] <= 100000 && !visited[check_idx[i]])
			{
				to_visit.push(check_idx[i]);
				visited[check_idx[i]] = true;
				(i == 0) ? time[check_idx[i]] = time[x] : time[check_idx[i]] = time[x] + 1;
			}
		}
	}

	cout << time[k] << "\n";
}