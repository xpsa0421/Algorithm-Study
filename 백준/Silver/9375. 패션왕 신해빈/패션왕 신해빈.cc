#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_tests;
	cin >> num_tests;

	while (num_tests--)
	{
		int num_clothes;
		cin >> num_clothes;

		unordered_map<string, int> types;
		for (int i = 0; i < num_clothes; i++)
		{
			string clothes_type;
			cin >> clothes_type >> clothes_type;
			types[clothes_type]++;
		}
		
		if (num_clothes == 0)
		{
			cout << 0 << "\n";
			continue;
		}

		int total = 1;
		for (auto iter = types.begin(); iter != types.end(); iter++)
		{
			total *= (*iter).second + 1;
		}
	
		cout << --total << "\n";
	}
}