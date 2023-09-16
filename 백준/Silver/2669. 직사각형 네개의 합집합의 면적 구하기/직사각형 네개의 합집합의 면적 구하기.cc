#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	bool is_filled[101][101];
	memset(is_filled, false, sizeof(is_filled));

	// initialisation
	for (int i = 0; i < 4; i++)
	{
		int x_start, y_start, x_end, y_end;
		cin >> x_start >> y_start >> x_end >> y_end;

		for (int x = x_start; x < x_end; x++)
		{
			for (int y = y_start; y < y_end; y++)
			{
				is_filled[x][y] = true;
			}
		}
	}

	// solve
	int size = 0;
	for (int x = 1; x < 101; x++)
	{
		for (int y = 1; y < 101; y++)
		{
			if (is_filled[x][y]) size++;
		}
	}

	// output
	cout << size;
}