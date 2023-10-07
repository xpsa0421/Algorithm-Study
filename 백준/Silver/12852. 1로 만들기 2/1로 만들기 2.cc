#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int x = 0;
	cin >> x;

	// solve
	vector<int> dp(x + 1, x + 1);
	vector<int> prevs(x + 1, 0);
	dp[x] = 0;
	for (int i = x; i > 1; i--)
	{
		if (i % 3 == 0 && i / 3 > 0 && dp[i / 3] > dp[i] + 1)
		{
			prevs[i / 3] = i;
			dp[i / 3] = dp[i] + 1;
		}

		if (i % 2 == 0 && i / 2 > 0 && dp[i / 2] > dp[i] + 1)
		{
			prevs[i / 2] = i;
			dp[i / 2] = dp[i] + 1;
		}

		if (dp[i - 1] > dp[i] + 1)
		{
			prevs[i - 1] = i;
			dp[i - 1] = dp[i] + 1;
		}
	}

	// output
	cout << dp[1] << "\n";
	int prev = 1;
	stack<int> s;
	while (prev != 0)
	{
		s.push(prev);
		prev = prevs[prev];
	}

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}
