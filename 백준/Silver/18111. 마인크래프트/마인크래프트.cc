#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_rows = 0, num_cols = 0, init_blocks = 0;
	cin >> num_rows >> num_cols >> init_blocks;
	vector<int> heights(num_rows * num_cols);

	for (int i = 0; i < num_rows * num_cols; i++)
	{
		cin >> heights[i];
	}
	sort(heights.begin(), heights.end(), greater<>());

	int max_time = 2147483646;
	int best_height = 0;
	int min_target = heights[num_rows * num_cols - 1];
	int max_target = heights[0];

	for (int target_height = max_target; target_height >= min_target; target_height--)
	{
		int blocks = init_blocks;
		int time = 0;

		for (auto height : heights)
		{
			if (height > target_height)
			{
				blocks += (height - target_height);
				time += (height - target_height) * 2;
			}
			else if (height < target_height)
			{
				if (blocks < target_height - height)
				{
					time = max_time + 1;
					break;
				}
				blocks -= target_height - height;
				time += (target_height - height);
			}
		}

		if (time < max_time)
		{
			max_time = time;
			best_height = target_height;
		}
	}

	cout << max_time << " " << best_height;
}