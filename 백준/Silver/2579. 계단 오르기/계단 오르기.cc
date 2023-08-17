#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_stairs;
	cin >> num_stairs;

	int scores[301] = { 0 };
	int maxes[301] = { 0 };

	for (int i = 1; i <= num_stairs; i++)
	{
		cin >> scores[i];
	}

	maxes[0] = 0;
	maxes[1] = scores[1];
	maxes[2] = scores[1] + scores[2];

	for (int i = 3; i <= num_stairs; i++)
	{
		maxes[i] = scores[i] + max(/*두칸 전*/maxes[i - 2], /*한칸 전*/scores[i - 1] + maxes[i - 3]);
	}

	cout << maxes[num_stairs];
}
