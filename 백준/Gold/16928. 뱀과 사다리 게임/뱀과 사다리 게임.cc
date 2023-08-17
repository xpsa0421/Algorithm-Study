#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1000
using namespace std;

int special[101] = { 0 };
int depths[101] = { 0 };
bool visited[101] = { 0 };
void BFS(int start);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_ladders, num_snakes;
	cin >> num_ladders >> num_snakes;

	fill(depths, depths + 101, MAX);

	for (int i = 0; i < num_ladders + num_snakes; i++)
	{
		int start, end;
		cin >> start >> end;
		special[start] = end;
	}

	BFS(1);
	cout << depths[100];
}

void BFS(int start)
{
	queue<int> to_visit;
	to_visit.push(start);
	depths[start] = 0;
	visited[start] = true;

	while (!to_visit.empty())
	{
		int curr = to_visit.front();
		to_visit.pop();

		for (int i = 1; i <= 6; i++)
		{
			if (curr + i > 100) break;

			if (special[curr + i] && !visited[curr + i])
			{
				depths[curr + i] = min(depths[curr + i], depths[curr] + 1);
				depths[special[curr + i]] = min(depths[special[curr + i]], depths[curr + i]);
				to_visit.push(special[curr + i]);
			}
			else if (!special[curr + i] && !visited[curr + i])
			{
				depths[curr + i] = min(depths[curr + i], depths[curr] + 1);
				to_visit.push(curr + i);
			}

			visited[curr + i] = true;
		}
	}
}