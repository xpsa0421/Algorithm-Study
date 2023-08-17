#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	int num_digits = floor(log10(n) + 1);
	int comp = max(0, n - 9 * num_digits);

	while (comp < n)
	{
		int divider = 1000000;
		int sum = comp;
		int temp = comp;

		while (divider > 0)
		{		
			sum += temp / divider;
			temp -= (temp / divider) * divider;
			divider /= 10;
		}

		if (sum == n) break;
		comp++;
	}
	cout << (comp == n ? 0 : comp);
}