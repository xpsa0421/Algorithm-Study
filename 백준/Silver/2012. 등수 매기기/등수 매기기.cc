#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	vector<int> ranks(n, 0);
	for (int i = 0; i < n; i++) cin >> ranks[i];
	sort(ranks.begin(), ranks.end());

	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += abs(ranks[i - 1] - i);
	}

	cout << ans;
}
