#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int count = 0;
	unordered_map<int, string> pokemons_by_index;
	unordered_map<string, int> pokemons_by_name;

	while (n--)
	{
		string name;
		cin >> name;
		pokemons_by_index.insert(make_pair(++count, name));
		pokemons_by_name.insert(make_pair(name, count));
	}

	while (m--)
	{
		string s;
		cin >> s;

		if (isdigit(s[0]))
		{
			cout << (pokemons_by_index.find(stoi(s))->second) << "\n";
		}
		else
		{
			cout << (pokemons_by_name.find(s)->second) << "\n";
		}
	}
}