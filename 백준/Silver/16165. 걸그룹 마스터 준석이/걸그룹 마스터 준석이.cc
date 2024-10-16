#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	unordered_map<string, vector<string>> teams;
	unordered_map<string, string> nameToTeam;

	string team, name;
	int cnt;
	while (n--)
	{
		cin >> team >> cnt;
		vector<string> names(cnt, "");
		for (int i = 0; i < cnt; i++)
		{
			cin >> names[i];
			nameToTeam[names[i]] = team;
		}
		sort(names.begin(), names.end());
		teams[team] = names;
	}

	string query; int type;
	while (m--)
	{
		cin >> query >> type;
		if (type == 0)
		{
			for (string n : teams[query]) cout << n << '\n';
		}
		else
		{
			cout << nameToTeam[query] << '\n';
		}
	}
}
