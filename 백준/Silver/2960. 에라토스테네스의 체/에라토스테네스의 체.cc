#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<bool> isPrime(n + 1, true);
	for (int i = 2; i <= n; i++)
	{
		if (!isPrime[i]) continue;

		// 본인 지우기
		if (--k == 0)
		{
			cout << i << '\n';
			return 0;
		}

		for (int j = i * i; j <= n; j += i)
		{
			if (isPrime[j])
			{
				isPrime[j] = false;
				if (--k == 0)
				{
					cout << j << '\n';
					return 0;
				}
			}
		}
	}
}
