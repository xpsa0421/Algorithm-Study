#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	string str;
	getline(cin, str);

	while (str != ".")
	{
		stack<char> stack;

		for (char& c : str)
		{
			if (c == '.') break;

			if (c == '(' or c == '[')
			{
				stack.push(c);
			}
			else if (c == ')')
			{
				if (stack.empty())
				{
					stack.push(c);
					break;
				}
				if (stack.top() == '[')
				{
					break;
				}
				if (stack.top() == '(')
				{
					stack.pop();
				}
			}
			else if (c == ']')
			{
				if (stack.empty())
				{
					stack.push(c);
					break;
				}
				if (stack.top() == '(')
				{
					break;
				}
				if (stack.top() == '[')
				{
					stack.pop();
				}
			}
		}
		
		if (stack.empty())
			cout << "yes\n";
		else
			cout << "no\n";

		getline(cin, str);
	}
}