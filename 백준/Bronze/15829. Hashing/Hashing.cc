#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int len;
	long long hash = 0;
	string s;
	cin >> len >> s;

	long power = 1;
	for (int i = 0; i < len; i++)
	{
		hash += (s[i] - 'a' + 1) * power;
		hash %= 1234567891;
		power = power * 31 % 1234567891;
	}

	cout << hash;
}