#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	string s;
	while (1)
	{
		cin >> s;
		if (s == "end") break;

		char prev_char = ' ';
		bool prev_moem = false;
		bool prev_prev_moem = false;
		bool rule2_checked = false;
		bool rule1_checked = true;
		bool rule3_checked = false;
		for (int i = 0; i < s.length(); i++)
		{
			char c = s[i];
			bool is_moem = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
			if (rule1_checked && is_moem)
			{
				rule1_checked = false;  
			}
			if (!rule2_checked && i >= 2 && is_moem == prev_moem && prev_prev_moem == prev_moem)
			{
				rule2_checked = true;
				break;
			}
			if (i >= 1 && prev_char == c)
			{
				if (c == 'e' || c == 'o') continue;
				rule3_checked = true;
				break;
			}

			prev_prev_moem = prev_moem;
			prev_moem = is_moem;
			prev_char = c;
		}

		cout << "<" << s << "> is " << (!rule1_checked && !rule2_checked && !rule3_checked ? "" : "not ") << "acceptable.\n";
	}
}
