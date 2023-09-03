#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int heights[9];
	for (int i = 0; i < 9; i++)
	{
		cin >> heights[i];
	}

	for (int first = 0; first < 8; first++)
	{
		for (int second = first + 1; second < 9; second++)
		{
			int total = 0;
			vector<int> heights_final;
			for (int i = 0; i < 9; i++)
			{
				if (i == first || i == second) continue;
				total += heights[i];
				heights_final.push_back(heights[i]);
			}
			if (total == 100)
			{
				sort(heights_final.begin(), heights_final.end());
				for (int height : heights_final)
				{
					cout << height << "\n";
				}
				return 0;
			}
		}
	}
}