#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_commands;
	cin >> num_commands;

	int s = 0;
	string command;

	while (num_commands--)
	{
		cin >> command;

		if (command == "add")
		{
			int x;
			cin >> x;
			s |= (1 << (x - 1));
		}
		else if (command == "remove")
		{
			int x;
			cin >> x;
			s &= ~(1 << (x - 1));
		}
		else if (command == "check")
		{
			int x;
			cin >> x;
			cout << ((s & (1 << (x - 1))) ? 1 : 0) << '\n';
		}
		else if (command == "toggle")
		{
			int x;
			cin >> x;
			s ^= (1 << (x - 1));
		}
		else if (command == "all")
		{
			s = (1 << 20) - 1;
		}
		else if (command == "empty")
		{
			s = 0;
		}
	}
}