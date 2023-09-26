#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int n = 0, target = 0;
	cin >> n >> target;

	vector<int> nums(n,0);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	// solve
	int count = 0, end = 0, curr_sum = nums[0];
	for (int start = 0; start < n; start++)
	{
		while (end < n && curr_sum < target)
		{
			end++;
			if (end != n) curr_sum += nums[end];
		}
		if (end == n)
		{
			break;
		}
		if (curr_sum == target) count++;
		curr_sum -= nums[start];
	}
	
	// output
	cout << count;
}