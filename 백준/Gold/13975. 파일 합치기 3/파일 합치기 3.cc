#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		int k = 0, p = 0;
		cin >> k;
		while (k--)
		{
			cin >> p;
			pq.push(p);
		}

		long long ans = 0;
		while (pq.size() > 1)
		{
			long long a = pq.top(); pq.pop();
			long long b = pq.top(); pq.pop();
			ans += a + b;
			pq.push(a + b);
		}

		cout << ans << '\n';
	}
}
