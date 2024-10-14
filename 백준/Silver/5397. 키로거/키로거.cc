#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		string input;
		cin >> input;

		list<char> password;
		auto it = password.begin();

		for (char c : input)
		{
			switch (c)
			{
			case '<':
				if (it != password.begin()) it--;
				break;

			case '>':
				if (it != password.end()) it++;
				break;

			case '-':
				if (it != password.begin())
				{
					it--;
					it = password.erase(it);
				}
				break;

			default:
				password.insert(it, c);
				break;
			}
		}

		cout << string(password.begin(), password.end()) << '\n';
	}
}