#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int n = 0;
	cin >> n;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++) cin >> nums[i];

	// solve
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	
	// output
	for (int n : nums)
	{
		cout << n << " ";
	}
}