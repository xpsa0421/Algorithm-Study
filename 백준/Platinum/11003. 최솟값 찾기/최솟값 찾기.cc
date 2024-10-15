#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <list>
#include <deque>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, l;
	cin >> n >> l;

	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++) cin >> nums[i];
	
	// num, index
	deque<pair<int,int>> dq;
	vector<int> ans(n, 0);
	for (int i = 0; i < n; i++)
	{
		// 고려 대상이 아닌 인덱스는 제거
		if (!dq.empty() && dq.front().second + l == i)
		{
			dq.pop_front();
		}

		// 더 작은 숫자가 들어오면 그보다 큰 숫자는 제거
		while (!dq.empty() && dq.back().first > nums[i])
		{
			dq.pop_back();
		}

		dq.push_back({ nums[i], i });
		ans[i] = dq.front().first;
	}
	
	for (int n : ans) cout << n << ' ';
}