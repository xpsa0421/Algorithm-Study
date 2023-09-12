#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int n = 0;
	cin >> n;

	vector<vector<int>> links(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		
		links[a].push_back(b);
		links[b].push_back(a);		
	}

	// solution
	vector<int> parents(n + 1, 0);
	queue<int> to_visit;
	for (auto node : links[1])
	{
		parents[node] = 1;
		to_visit.push(node);
	}

	while (!to_visit.empty())
	{
		int i = to_visit.front();
		to_visit.pop();

		for (auto node : links[i])
		{
			if (parents[node] != 0 || node == 1) continue;
			parents[node] = i;
			to_visit.push(node);
		}
	}

	for (int i = 2; i <= n; i++)
	{
		cout << parents[i] << "\n";
	}
}