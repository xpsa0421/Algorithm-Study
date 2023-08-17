#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	int workhour[4] = { 4, 6, 4, 10 };
	unordered_map<string, int> map;
	for (int i = 0; i < n; i++)
	{
		for (int time = 0; time < 4; time++)
		{
			for (int day = 0; day < 7; day++)
			{
				string worker; 
				cin >> worker;
				
				if (worker != "-") map[worker] += workhour[time];
			}
		}
	}

	bool is_fair = true;
	for (auto iter = map.begin(); iter != map.end(); iter++)
	{
		for (auto next_iter = next(iter); next_iter != map.end(); next_iter++)
		{
			if (abs(iter->second - next_iter->second) > 12)
			{
				is_fair = false;
				goto end;
			}
		}
	}

end:
	cout << (is_fair ? "Yes" : "No");
}