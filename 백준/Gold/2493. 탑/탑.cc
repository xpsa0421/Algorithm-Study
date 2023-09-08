#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	// stack<height, index>
	stack<pair<int, int>> s;

	// input maximum+1 value
	s.emplace(100000001, 0);

	for (int i = 1; i <= n; i++)
	{
		int curr;
		cin >> curr;

		while (s.top().first < curr)
		{
			s.pop();
		}

		cout << s.top().second << " ";
		s.emplace(curr, i);
	}

	return 0;
}