#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	int sum = 0;
	vector<int> nums;
	unordered_map<int, int> nums_map;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		
		nums.push_back(num);
		nums_map[num]++;
		sum += num;
	}

	sort(nums.begin(), nums.end());

	int avg = round(sum / (double)n);
	int mid = nums[(n - 1) / 2]; 
	int range = nums[n - 1] - nums[0];
	int mode = nums_map.begin()->first;

	if (nums_map.size() > 1)
	{
		vector<pair<int, int>> nums_map_v(nums_map.begin(), nums_map.end());
		sort(nums_map_v.begin(), nums_map_v.end(), [](pair<int, int>& a, pair<int, int>& b) {
			if (a.second == b.second)
			{
				return a.first < b.first;
			}
			else return a.second > b.second;
			});

		if (nums_map_v.begin()->second == (nums_map_v.begin() + 1)->second)
		{
			mode = (nums_map_v.begin() + 1)->first;
		}
		else
		{
			mode = nums_map_v.begin()->first;
		}
	}

	cout << avg << "\n" << mid << "\n" << mode << "\n" << range;
}