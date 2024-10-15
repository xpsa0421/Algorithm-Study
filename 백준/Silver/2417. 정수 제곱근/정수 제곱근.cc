#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	long long n;
	cin >> n;

	long long q = sqrt(n);
	if ((q * q) < n) q++;

	cout << q;
}