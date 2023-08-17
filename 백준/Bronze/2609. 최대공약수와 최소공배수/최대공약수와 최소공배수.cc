#include <iostream>
using namespace std;

int GetGCD(int a, int b);

int main()
{
	int a, b;
	cin >> a >> b;

	int gcd = GetGCD(a, b);
	int lcm = (a * b) / gcd;
	cout << gcd << endl << lcm;

	return 0;
}

int GetGCD(int a, int b)
{
	if (a == 0) return b;
	if (b == 0) return a;
	if (a == b) return a;

	if (a > b)
	{
		if (a % b == 0) return b;
		else return GetGCD(a - b, b);
	}
	else
	{
		if (b % a == 0) return a;
		else return GetGCD(b - a, a);
	}
}