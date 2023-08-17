#include <iostream>
#include <stdio.h>
using namespace std;

bool IsPrime(int n);

int main() {
	int n, count = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		
		if (IsPrime(num)) count++;
	}

	printf("%d", count);
	return 0;
}

bool IsPrime(int n)
{
	if (n <= 1) return false;

	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}