#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	string s;
	int m;
	cin >> s >> m;

	list<char> nums;
	for (char& c : s) nums.push_back(c);

	// 명령어 수행
	list<char>::iterator it = nums.end();
	while (m--)
	{
		char c;
		cin >> c;

		switch (c)
		{
		case 'L':
			if (it != nums.begin()) it--;
			break;

		case 'D':
			if (it != nums.end()) it++;
			break;

		case 'B':
			if (it != nums.begin()) nums.erase(prev(it));
			break;

		case 'P':
			cin >> c;
			nums.insert(it, c);
			break;
		}
	}

	cout << string(nums.begin(), nums.end());
}