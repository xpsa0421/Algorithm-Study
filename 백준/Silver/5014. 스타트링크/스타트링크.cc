#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int max, current, target, up_by, down_by;
	cin >> max >> current >> target >> up_by >> down_by;

	vector<bool> visited(max + 1, false);
	vector<int> counts(max + 1, 0);
	queue<int> to_visit;

	visited[current] = true;
	to_visit.push(current);

	while (!to_visit.empty())
	{
		current = to_visit.front();
		to_visit.pop();

		if (current == target)
		{
			cout << counts[current];
			return 0;
		}

		int nexts[2] = { current - down_by, current + up_by };
		for (int next : nexts)
		{
			if (next > 0 && next <= max && !visited[next])
			{
				visited[next] = true;
				to_visit.push(next);
				counts[next] = counts[current] + 1;
			}
		}		
	}

	cout << "use the stairs";
	return 0;
}