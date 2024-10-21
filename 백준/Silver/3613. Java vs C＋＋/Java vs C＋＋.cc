#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{ 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;

	bool isFixedCpp = false;
	bool isFixedJava = false;
	bool isNextCapital = false;
	bool isError = false;
	int diff = 'A' - 'a';

	string output = "";
	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		if (c == '_')
		{
			if (i == 0 || i == s.length() - 1 || isFixedJava || isNextCapital)
			{
				isError = true;
				break;
			}
			else
			{
				isFixedCpp = true;
				isNextCapital = true;
			}
		}
		else if ('a' <= c && c <= 'z')
		{
			if (isNextCapital)
			{
				output += c + diff;
				isNextCapital = false;
			}
			else output += c;
		}
		else // 대문자
		{
			if (isFixedCpp || i == 0)
			{
				isError = true;
				break;
			}
			else
			{
				isFixedJava = true;
				output += '_';
				output += c - diff;
			}
		}
	}

	cout << (isError ? "Error!" : output);
}
