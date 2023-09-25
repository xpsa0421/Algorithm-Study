#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int n = 0, min_sum = 0;
	cin >> n >> min_sum;

	vector<int> nums(n,0);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	// solve
	int min_len = 0x7fffffff;
	int end = 0, curr_sum = nums[0];
	for (int start = 0; start < n; start++)
	{
		while (end < n && curr_sum < min_sum)
		{
			end++;
			if (end != n) curr_sum += nums[end];
		}
		if (end == n)
		{
			break;
		}
		min_len = min(min_len, end - start + 1);
		curr_sum -= nums[start];
	}
	
	// output
	cout << (min_len == 0x7fffffff ? 0 : min_len);
}