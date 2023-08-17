#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	stack<int> s;
	vector<int> orders(n);

	for (int i = 0; i < n; i++)
	{
		cin >> orders[i];
	}

	vector<char> answer;
	int pushed_max = 0;
	s.push(0);

	for (int num : orders)
	{
		while (s.top() != num)
		{
			if (s.top() < num)
			{
				s.push(++pushed_max);
				answer.push_back('+');
			}
			else if (s.top() > num)
			{
				cout << "NO";
				return 0;
			}
		}
		s.pop();
		answer.push_back('-');
	}

	for (char& c : answer)
	{
		cout << c << "\n";
	}
}
