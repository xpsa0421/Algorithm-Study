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

	int n = 0;
	cin >> n;
	n *= 2;

	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());
	int curr_min = nums[n-1] * 2;

	int start = 0;
	int end = n - 1;

	while (start < end)
	{
		curr_min = min(curr_min, nums[start] + nums[end]);
		start++;
		end--;
	}

	cout << curr_min;
}
