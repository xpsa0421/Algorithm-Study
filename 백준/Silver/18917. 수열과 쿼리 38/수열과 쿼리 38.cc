#include <iostream>
#include <vector>
using namespace std;

int dp[1001][1001];
int mod = 10007;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int m;
	cin >> m;

	int query, x;
	long long sum = 0; int xorSum = 0;
	while (m--)
	{
		cin >> query;
		switch (query)
		{
		case 1:
			cin >> x;
			sum += x;
			xorSum ^= x;
			break;

		case 2:
			cin >> x;
			sum -= x;
			xorSum ^= x;
			break;

		case 3:
			cout << sum << '\n';
			break;

		case 4:
			cout << xorSum << '\n';
			break;
		}
	}
}
