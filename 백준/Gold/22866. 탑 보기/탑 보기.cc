#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> heights(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> heights[i];

	stack<pair<int,int>> stk; // idx, height
	vector<int> counts(n + 1, 0);
	vector<int> nears(n + 1, 0);
	
	for (int i = 1; i <= n; i++)
	{
		while (!stk.empty() && stk.top().second <= heights[i])
			stk.pop();
		if (!stk.empty()) 
			nears[i] = stk.top().first;
		counts[i] = stk.size();
		stk.push({ i, heights[i] });
	}

	while (!stk.empty()) stk.pop();

	for (int i = n; i > 0; i--)
	{
		while (!stk.empty() && stk.top().second <= heights[i])
			stk.pop();
		if (!stk.empty())
		{
			if (nears[i] == 0)
				nears[i] = stk.top().first;
			else if (abs(i - stk.top().first) < abs(i - nears[i]))
				nears[i] = stk.top().first;
		}
			
		counts[i] += stk.size();
		stk.push({ i, heights[i] });
	}

	for (int i = 1; i <= n; i++)
	{
		if (counts[i] == 0)
			cout << "0\n";
		else
			cout << counts[i] << ' ' << nears[i] << '\n';
	}
}