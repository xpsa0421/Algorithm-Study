#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, x, y, num_relations;
	cin >> n >> x >> y >> num_relations;

	vector<vector<int>> relations(101);

	while (num_relations--)
	{
		int parent, child;
		cin >> parent >> child;

		relations[parent].push_back(child);
		relations[child].push_back(parent);
	}

	if (x == y)
	{
		cout << 0;
		return 0;
	}

	queue<int> to_visit;
	bool visited[101] = { false };
	int relation_counts[101];
	memset(relation_counts, 0, sizeof(relation_counts));
	to_visit.push(x);
	visited[x] = true;

	while (!to_visit.empty())
	{
		int check_idx = to_visit.front();
		to_visit.pop();

		for (int related : relations[check_idx])
		{
			if (!visited[related])
			{
				relation_counts[related] = relation_counts[check_idx] + 1;
				visited[related] = true;
				to_visit.push(related);
				
				if (related == y)
				{
					cout << relation_counts[related];
					return 0;
				}
			}
		}
	}

	cout << -1;
	return 0;
}