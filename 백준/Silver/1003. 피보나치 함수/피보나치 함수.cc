#include <iostream>
using namespace std;

void FillFiboTable();

int fibo_table[41][2];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	FillFiboTable();

	int n, x;
	cin >> n;
	
	while (n--)
	{
		cin >> x;
		cout << fibo_table[x][0] << " " << fibo_table[x][1] << "\n";
	}
}

void FillFiboTable()
{
	// base case
	fibo_table[0][0] = 1;
	fibo_table[1][1] = 1;

	for (int i = 2; i <= 40; i++)
	{
		fibo_table[i][0] = fibo_table[i - 1][0] + fibo_table[i - 2][0];
		fibo_table[i][1] = fibo_table[i - 1][1] + fibo_table[i - 2][1];
	}
}
