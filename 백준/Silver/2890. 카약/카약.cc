#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int rows = 0, cols = 0;
	cin >> rows >> cols;

	vector<pair<int,int>> distances;
	int team_counts = 0;
	for (int r = 0; r < rows; r++)
	{
		char curr = ' ';
		bool is_valid = false;
		for (int c = 0; c < cols; c++)
		{
			cin >> curr;
			if (is_valid)
			{
				distances[team_counts].first++;
			}
			else if (isdigit(curr))
			{
				is_valid = true;
				distances.emplace_back(0, curr - '0' - 1);
				c += 2;
				cin >> curr;
				cin >> curr;
			}
		}
		if (is_valid)
		{
			team_counts++;
		}
	}

	sort(distances.begin(), distances.end());
	int rank = 1;
	vector<int> ranks(9,0);
	ranks[distances[0].second] = 1;
	for (int i = 1; i < 9; i++)
	{
		if (distances[i].first != distances[i - 1].first)
		{
			rank++;
		}
		ranks[distances[i].second] = rank;
	}

	for (int i = 0; i < 9; i++)
	{
		cout << ranks[i] << "\n";
	}
}
