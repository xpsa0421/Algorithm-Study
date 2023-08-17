#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_types, target, count = 0;
	cin >> num_types >> target;

	vector<int> coins;
	for (int i = 0; i < num_types; i++)
	{
		int value;
		cin >> value;
		coins.push_back(value);
	}
	
	while (target > 0)
	{
		auto iter = lower_bound(coins.begin(), coins.end(), target); // 현재 타겟 이상
		if (*iter == target)
		{
			target = 0;
			count++;
		}
		else
		{
			int coin = *(iter - 1);
			count += target / coin;
			target -= coin * (target / coin);
		}
	}

	cout << count;
}