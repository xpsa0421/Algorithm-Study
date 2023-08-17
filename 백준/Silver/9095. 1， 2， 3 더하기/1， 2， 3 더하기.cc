#include <iostream>
#include <vector>
using namespace std;

int FindVarieties(int n);
int varieties[11];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	varieties[1] = 1;
	varieties[2] = 2;
	varieties[3] = 4;

	while (t--)
	{
		int n;
		cin >> n;
		cout << FindVarieties(n) << "\n";
	}
}

int FindVarieties(int n)
{
	if (varieties[n] == 0)
	{
		varieties[n] = FindVarieties(n - 1) + FindVarieties(n - 2) + FindVarieties(n - 3);
	}
	return varieties[n];
}