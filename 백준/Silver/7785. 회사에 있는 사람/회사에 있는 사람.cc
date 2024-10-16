#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	unordered_set<string> ppl;
	while (n--)
	{
		string name, state;
		cin >> name >> state;
		if (state == "enter") ppl.insert(name);
		else ppl.erase(name);
	}

	vector<string> pplFinal(ppl.begin(), ppl.end());
	sort(pplFinal.begin(), pplFinal.end(), greater<string>());

	for (string p : pplFinal)
	{
		cout << p << '\n';
	}
}