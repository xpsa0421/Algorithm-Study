#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a == 0 && b == 0 && c == 0) break;

		int side = max(max(a, b), c);

		if (a == side)
		{
			if (a * a == b * b + c * c)
			{
				printf("right\n");
				continue;
			}
		}
		else if (b == side)
		{
			if (b * b == a * a + c * c)
			{
				printf("right\n");
				continue;
			}
		}
		else if (c == side)
		{
			if (c * c == b * b + a * a)
			{
				printf("right\n");
				continue;
			}
		}
		
		printf("wrong\n");
	}

	return 0;
}