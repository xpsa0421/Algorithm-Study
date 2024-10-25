#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int nums[1000000];
int indices[1000000];

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
	indices[0] = 1;
	int maxLen = 1;
	for (int i = 1; i < n; i++)
	{
		// back보다 크면 바로 삽입
		if (temp.back() < nums[i])
		{
			temp.push_back(nums[i]);
			indices[i] = ++maxLen;
		}
		// 아니라면 더 작은 원소 뒤에 삽입
		else
		{
			auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
			*it = nums[i];
			indices[i] = it - temp.begin() + 1;
		}
	}

	// Solve - Backtrace
	vector<int> res; res.reserve(maxLen);
	for (int i = n - 1; i >= 0; i--)
	{
		if (indices[i] == maxLen)
		{
			res.push_back(nums[i]);
			maxLen--;
			if (maxLen == 0) break;
		}
	}

	// Output
	cout << res.size() << '\n';
	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i] << ' ';
}