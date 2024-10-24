#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<int>> universe;
vector<vector<int>> compressed;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// Input
	int m, n;
	cin >> m >> n;
	universe.resize(m, vector<int>(n, 0));

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> universe[i][j];

	// Coordinate compression
	compressed.resize(m);
	for (int i = 0; i < m; i++)
	{
		vector<int> temp = universe[i];
		std::sort(temp.begin(), temp.end());
		temp.erase(unique(temp.begin(), temp.end()), temp.end());
		compressed[i].resize(temp.size());

		// Compress each planet
		for (int j = 0; j < n; j++)
			compressed[i][j] = lower_bound(temp.begin(), temp.end(), universe[i][j]) - temp.begin();
	}
	std::sort(compressed.begin(), compressed.end());

	// Comparison
	int ans = 0;
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			int size = compressed[i].size();
			if (size != compressed[j].size()) break;
			
			bool isDiff = false;
			for (int k = 0; k < size; k++)
			{
				if (compressed[i][k] != compressed[j][k])
				{
					isDiff = true;
					break;
				}
			}
			if (isDiff) break;
			else ans++;
		}
	}

	// Answer
	cout << ans;
}