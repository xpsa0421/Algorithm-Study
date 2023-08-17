#include <iostream>
#include <vector>
#define INVALID 5000
using namespace std;

int dp_table[5001] = { 0 };
int GetDP(int n);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	dp_table[3] = 1;
	dp_table[4] = INVALID;
	dp_table[5] = 1;

	int res = GetDP(n);
	cout << (res != INVALID ? res : -1);
}

int GetDP(int n)
{
	if (n < 3) return INVALID;
	if (dp_table[n] != 0) return dp_table[n];

	dp_table[n] = min(GetDP(n - 3), GetDP(n - 5));
	if (dp_table[n] != INVALID) dp_table[n]++;
	
	return dp_table[n];
}