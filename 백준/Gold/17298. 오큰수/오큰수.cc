#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int n = 0;
	cin >> n;

	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	// solution
	stack<int> s;
	s.push(nums[n - 1]);
	vector<int> ans(n, -1);
	for (int i = n - 2; i >= 0; i--)
	{
		while (!s.empty() && s.top() <= nums[i])
		{
			s.pop();
		}
		if (!s.empty())
		{
			ans[i] = s.top();
		}
		s.push(nums[i]);
	}

	for (auto answer : ans)
	{
		cout << answer << " ";
	}
}