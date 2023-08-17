#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	string s;

	while (cin >> s)
	{
		if (s == "0") break;

		bool is_palin = true;
		int len = s.length();
		for (int i = 0; i < len / 2; i++)
		{
			if (s[i] != s[len - 1 - i])
			{
				is_palin = false;
				break;
			}
		}

		if (is_palin) printf("yes\n");
		else printf("no\n");
	}

	return 0;
}