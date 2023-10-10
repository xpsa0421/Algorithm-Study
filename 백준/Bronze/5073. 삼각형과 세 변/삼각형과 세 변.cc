#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int x = 0, y = 0, z = 0;
	while (1)
	{
		cin >> x >> y >> z;
		if (x == 0 && y == 0 && z == 0) break;

		int max_len = 0, sum = 0;
		if (x > y)
		{
			max_len = x;
			sum += y;
		}
		else
		{
			max_len = y;
			sum += x;
		}
		if (z > max_len)
		{
			sum += max_len;
			max_len = z;
		}
		else
		{
			sum += z;
		}
		if (max_len >= sum)
		{
			cout << "Invalid\n";
			continue;
		}

		if (x == y && y == z)
		{
			cout << "Equilateral\n";
		}
		else if (x == y || x == z || y == z)
		{
			cout << "Isosceles\n";
		}
		else
		{
			cout << "Scalene\n";
		}
	}
}
