#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_set>
#include <array>
using namespace std;
#define MAX 0x7f7f7f7f
#define MOD 1000000007

typedef vector<vector<long long>> matrix;
const matrix F = { {1,1},{1,0} };

matrix multiply(const matrix& a, const matrix& b)
{
	return {
		{
			(a[0][0] * b[0][0] % MOD + a[0][1] * b[1][0] % MOD) % MOD,
			(a[0][0] * b[0][1] % MOD + a[0][1] * b[1][1] % MOD) % MOD
		},
		{
			(a[1][0] * b[0][0] % MOD + a[1][1] * b[1][0] % MOD) % MOD,
			(a[1][0] * b[0][1] % MOD + a[1][1] * b[1][1] % MOD) % MOD
		}
	};
}

matrix power(long long exp)
{
	if (exp == 1)
	{
		return F;
	}
	if (exp % 2 == 0)
	{
		matrix res = power(exp / 2);
		return multiply(res, res);
	}
	else
	{
		matrix res = power(exp - 1);
		return multiply(F, res);
	}
}

long long fibonacci(long long n)
{
	if (n == 1) return 1;
	matrix res = power(n - 1);
	return res[0][0];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n; cin >> n;
	cout << fibonacci(n) % MOD;
}
