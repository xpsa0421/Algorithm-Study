#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	string s;
	cin >> s;

	vector<int> counts(26, 0);
	for (char c : s)
	{
		if (c >= 'a') c -= 'a';
		else c -= 'A';

		counts[c]++;
	}

	int max_count = 0;
	int max_char = 0;
	int max_occr = 1;
	for (int i = 0; i < 26; i++)
	{
		if (counts[i] > max_count)
		{
			max_count = counts[i];
			max_char = i;
			max_occr = 1;
		}
		else if (counts[i] == max_count)
		{
			max_occr++;
		}
	}

	if (max_occr > 1) cout << '?';
	else cout << char(max_char + 'A');
}
