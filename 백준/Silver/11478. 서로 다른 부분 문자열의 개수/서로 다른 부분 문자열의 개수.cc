#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// Input
	string s; cin >> s;

	// Solve
	unordered_set<string> p;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i + 1; j <= s.size(); j++)
		{
			p.insert(s.substr(i, j - i));
		}
	}

	// Output
	cout << p.size();
}