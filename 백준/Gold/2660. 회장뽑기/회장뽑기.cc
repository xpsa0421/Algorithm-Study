#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int distances[51][51];
	fill(&distances[0][0], &distances[50][51], 51);

	int n = 0;
	cin >> n;

	for (int i = 0; i <= n; i++)
	{
		distances[i][i] = 0;
	}

	while (1)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a == -1) break;

		distances[a][b] = 1;
		distances[b][a] = 1;
	}

	// solve
	for (int mid = 1; mid <= n; mid++)
	{
		for (int start = 1; start <= n; start++)
		{
			for (int end = 1; end <= n; end++)
			{
				distances[start][end] = min(distances[start][end], distances[start][mid] + distances[mid][end]);
			}
		}
	}

	int min_n = 51;
	vector<int> candidates;

	for (int i = 1; i <= n; i++)
	{
		int curr_n = 0;
		for (int j = 1; j <= n; j++)
		{
			curr_n = max(curr_n, distances[i][j]);
		}

		if (curr_n < min_n)
		{
			candidates.clear();
		}
		if (curr_n <= min_n)
		{
			min_n = curr_n;
			candidates.push_back(i);
		}
	}

	// output
	cout << min_n << " " << candidates.size() << "\n";
	for (int i : candidates)
	{
		cout << i << " ";
	}
}