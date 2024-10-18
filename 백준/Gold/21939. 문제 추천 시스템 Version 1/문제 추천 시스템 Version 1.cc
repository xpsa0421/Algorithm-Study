#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, p, l, m, x, P;
	set<pair<int, int>> questions; // level, no
	unordered_multimap<int, int> qLevels; // no : level

	cin >> n;
	while (n--)
	{
		cin >> p >> l;
		questions.insert({ l, p });
		qLevels.insert({ p, l });
	}
	
	cin >> m;
	string query = "";
	while (m--)
	{
		cin >> query;
		if (query == "recommend")
		{
			cin >> x;
			if (x == 1)
			{
				cout << (*prev(questions.end())).second << '\n';
			}
			else
			{
				cout << (*questions.begin()).second << '\n';
			}
		}
		else if (query == "add")
		{
			cin >> p >> l;
			questions.insert({ l, p });
			qLevels.insert({ p, l });
		}
		else
		{
			cin >> P;
			auto it = qLevels.find(P);
			while (it != qLevels.end())
			{
				questions.erase({ (*it).second, P });
				qLevels.erase(it);
				it = qLevels.find(P);
			}
		}
	}
}
