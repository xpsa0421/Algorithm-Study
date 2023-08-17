#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	unordered_map<int, int> nums;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		nums[num]++;
	}

	vector<pair<int, int>> nums_v(nums.begin(), nums.end());
	nums.clear();
	sort(nums_v.begin(), nums_v.end());

	for (auto iter = nums_v.begin(); iter != nums_v.end(); iter++)
	{
		for (int i = 0; i < iter->second; i++)
		{
			cout << iter->first << "\n";
		}
	}
}