#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
#define MAX 0x7f7f7f7f

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s; cin >> s;
	string explo; cin >> explo;

	stack<char> stk;
	for (char c : s)
	{
		stk.push(c);
		if (stk.size() >= explo.size())
		{
			vector<char> revTmp; bool exploded = true;
			for (int i = 1; i <= explo.size(); i++)
			{
				char rc = stk.top(); stk.pop();
				revTmp.push_back(rc);
				if (rc != explo[explo.size() - i])
				{
					exploded = false;
					break;
				}
			}
			if (!exploded)
			{
				for (int i = revTmp.size() - 1; i >= 0; i--)
				{
					stk.push(revTmp[i]);
				}
			}
		}
	}

	vector<char> res;
	while (!stk.empty())
	{
		res.push_back(stk.top());
		stk.pop();
	}

	if (res.size() == 0) cout << "FRULA";
	else
	{
		for (int i = res.size() - 1; i >= 0; i--)
			cout << res[i];
	}
}
