#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	vector<int> primes;
	vector<bool> isPrime(1000001, true);

	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= 1000000; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i + i; j <= 1000000; j += i)
		{
			isPrime[j] = false;
		}
	}
	primes.reserve(1000000);
	for (int i = 2; i <= 1000000; i++)
	{
		if (isPrime[i]) primes.push_back(i);
	}

	while (true)
	{
		int n; cin >> n;
		if (n == 0) break;

		bool isFound = false;
		if (n >= 4)
		{
			for (int p : primes)
			{
				if (isPrime[n - p])
				{
					cout << n << " = " << p << " + " << n - p << "\n";
					isFound = true;
					break;
				}
			}
		}
		
		if (!isFound)
		{
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}
}