#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		stack<char> chars;
		string s;

		cin >> s;
		for (int i = 0; i < s.length(); i++)
		{
			chars.push(s[i]);
		}

		bool is_valid = true;
		int unclosed = 0;

		if (chars.top() == '(')
		{
			is_valid = false;
		}

		while (!chars.empty() && is_valid)
		{
			char top = chars.top();
			chars.pop();

			if (top == ')')
			{
				unclosed++;
				if (unclosed > chars.size()) is_valid = false;
			}
			else
			{
				if (unclosed == 0) is_valid = false;
				else unclosed--;
			}
		}

		cout << (is_valid ? "YES" : "NO") << '\n';
	}
}