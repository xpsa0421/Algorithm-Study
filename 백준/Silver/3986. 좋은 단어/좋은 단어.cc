#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	int count = 0;
	while (n--)
	{
		string str;
		cin >> str;

		// 우선적 예외처리
		if (str.length() % 2 != 0)
		{
			continue;
		}

		// initialise
		bool is_good_word = true;
		stack<char> s;
		for (char& c : str)
		{
			if (s.empty() || s.top() != c)
			{
				s.push(c);
			}
			else 
			{
				s.pop();
			}
		}

		// 최종 검사
		if (s.empty())
		{
			count++;
		}
	}

	cout << count;
}