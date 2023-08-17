#include <iostream>
using namespace std;

int ones_table[1000001];
int MakeOneBottomUp(int n);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	ones_table[1] = 0;
	ones_table[2] = 1;
	ones_table[3] = 1;

	cout << MakeOneBottomUp(n) << "\n";
}

int MakeOneBottomUp(int n)
{
	for (int i = 4; i <= n; i++)
	{
		ones_table[i] = ones_table[i - 1] + 1;
		if (i % 3 == 0)
			ones_table[i] = min(ones_table[i], ones_table[i / 3] + 1);
		if (i % 2 == 0)
			ones_table[i] = min(ones_table[i], ones_table[i / 2] + 1);
	}

	return ones_table[n];
}