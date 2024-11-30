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
	
	int n;
	cin >> n;

	if (n == 1)
	{
		cout << 0;
		return 0;
	}

	vector<bool> isPrime(n+1, true);
	isPrime[0] = isPrime[1] = false;
	
	int end = sqrt(n);
	for (int i = 2; i <= end; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i + i; j <= n; j += i)
		{
			isPrime[j] = false;
		}
	}

	vector<int> primes;
	for (int i = 2; i <= n; i++)
	{
		if (isPrime[i]) primes.push_back(i);
	}

	int cnt = 0;
	int st = 0, en = 0;
	int sum = primes[st];
	int primeSize = primes.size();
	while (en < primeSize && st <= en)
	{
		if (sum == n)
		{
			cnt++;
			en++;

			if (en < primeSize)
			{
				sum += primes[en];
			}
			else break;
		}
		else if (sum < n)
		{
			en++;
			if (en < primeSize)
			{
				sum += primes[en];
			}
			else break;
		}
		else
		{
			sum -= primes[st];
			st++;
		}
	}

	cout << cnt;
}