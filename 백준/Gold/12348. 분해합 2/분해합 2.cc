#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

long long GetSum(long long n);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	long long n;
	cin >> n;

	int num_digits = floor(log10(n) + 1);
	long long comp = n - 9 * num_digits;
	if (comp <= 0) comp = 0;

	while (comp < n)
	{
		if (GetSum(comp) == n)
		{
			cout << comp;
			break;
		}
		comp++;
	}
	if (comp == n) cout << 0;
}

long long GetSum(long long n)
{
	string s = to_string(n);
	long long sum = n;
	for (int idx = 0; idx < s.length(); idx++)
	{
		sum += int(s[idx] - '0');
	}
	return sum;
}