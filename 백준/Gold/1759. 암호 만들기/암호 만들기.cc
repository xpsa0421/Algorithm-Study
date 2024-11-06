#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

int l, c;
vector<char> candidates;
string cur;

void solve(int len, int prevIdx)
{
	if (len == l)
	{
		int vowelCnt = 0, consCnt = 0;
		for (char c : cur)
		{
			switch (c)
			{
			case 'a': case 'e': case 'i': case 'o':	case 'u':
				vowelCnt++;
				break;

			default:
				consCnt++;
			}
		}
		if (vowelCnt >= 1 && consCnt >= 2)
			cout << cur << '\n';
		return;
	}

	for (int i = prevIdx + 1; i < c; i++)
	{
		cur[len] = candidates[i];
		solve(len + 1, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> l >> c;	
	cur.resize(l, ' ');
	candidates.resize(c);

	for (int i = 0; i < c; i++)
		cin >> candidates[i];
	sort(candidates.begin(), candidates.end());
	
	solve(0, -1);
}