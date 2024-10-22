#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_set>
using namespace std;
#define MAX 0x7f7f7f7f

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string inorder; cin >> inorder;
	stack<char> stk;

	for (char c : inorder)
	{
		if ('A' <= c && c <= 'Z')
		{
			cout << c;
			continue;
		}

		if (c == ')')
		{
			while (!stk.empty())
			{
				char stkTop = stk.top(); stk.pop();
				if (stkTop == '(') break;
				cout << stkTop;
			}
		}
		else if (c == '(')
		{
			stk.push(c);
		}
		else
		{
			if (c == '/' || c == '*')
			{
				if (!stk.empty())
				{
					char stkTop = stk.top();
					if (stkTop == '/' || stkTop == '*')
					{
						cout << stkTop;
						stk.pop();
					}
				}
				stk.push(c);
			}
			else
			{
				if (!stk.empty())
				{
					while (!stk.empty())
					{
						char stkTop = stk.top();
						if (stkTop == '(') break;
						cout << stkTop;
						stk.pop();
					}
				}
				stk.push(c);
			}
		}
	}

	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}
}
