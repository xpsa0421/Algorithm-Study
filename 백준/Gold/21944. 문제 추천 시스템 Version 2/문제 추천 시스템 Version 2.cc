#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, int> algoTypes; // 번호, 알고리즘
unordered_map<int, int> levels; // 번호, 난이도
set<pair<int, int>> questions; // 난이도, 번호

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;	cin >> n;
	int x, p, l, g;
	while (n--)
	{
		cin >> p >> l >> g;
		algoTypes[p] = g;
		levels[p] = l;
		questions.insert({ l,p });
	}

	int m; cin >> m;
	while (m--)
	{
		string query;
		cin >> query;

		if (query == "recommend")
		{
			cin >> g >> x;
			if (x == 1)
			{
				auto rit = questions.rbegin();
				while (true)
				{
					if (algoTypes[(*rit).second] == g)
					{
						cout << (*rit).second << '\n';
						break;
					}
					rit++;
				}
			}
			else
			{
				auto it = questions.begin();
				while (true)
				{
					if (algoTypes[(*it).second] == g)
					{
						cout << (*it).second << '\n';
						break;
					}
					it++;
				}
			}
		}
		else if (query == "recommend2")
		{
			cin >> x;
			if (x == 1) cout << (*questions.rbegin()).second << '\n';
			else cout << (*questions.begin()).second << '\n';
		}
		else if (query == "recommend3")
		{
			cin >> x >> l;
			auto it = questions.lower_bound({ l,0 });
			if (it == questions.end())
			{
				cout << -1 << '\n';
				continue;
			}
			if (x == 1)
			{
				cout << (*it).second << '\n';
			}
			else
			{
				if (it == questions.begin()) cout << -1 << '\n';
				else cout << (*--it).second << '\n';
			}
		}
		else if (query == "add")
		{
			cin >> p >> l >> g;
			algoTypes[p] = g;
			levels[p] = l;
			questions.insert({ l,p });
		}
		else
		{
			cin >> p;
			questions.erase({ levels[p], p });
		}
	}
}
