#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int nums[1000000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// Input
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	// Solve - Binary Search
	vector<int> temp; temp.reserve(10000000);
	temp.push_back(nums[0]);
	int maxLen = 1;

	for (int i = 1; i < n; i++)
	{
		// back보다 크면 바로 삽입
		if (temp.back() < nums[i])
		{
			temp.push_back(nums[i]);
			maxLen++;
		}
		// 아니라면 더 작은 원소 뒤에 삽입
		else
		{
			auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
			*it = nums[i];
		}
	}

	// Output
	cout << maxLen;
}