#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, sum = 0;
	cin >> n;
	stack<int> s;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num == 0)
			s.pop();
		else
			s.push(num);
	}

	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}

	cout << sum;
}