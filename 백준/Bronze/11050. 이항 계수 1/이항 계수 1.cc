#include <iostream>
#include <stdio.h>
using namespace std;

int Factorial(int n);

int main() {
	int n, k, coef = 0;
	cin >> n >> k;
	
	coef = Factorial(n) / (Factorial(k) * Factorial(n - k));

	printf("%d", coef);
	return 0;
}

int Factorial(int n)
{
	int res = n;

	if (n == 1 || n == 0)
	{
		res = 1;
	}
	else
	{
		for (int i = n - 1; i > 0; i--)
		{
			res *= i;
		}
	}
	
	return res;
}