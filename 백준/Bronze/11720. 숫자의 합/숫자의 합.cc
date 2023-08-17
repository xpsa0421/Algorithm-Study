#include <iostream>
using namespace std;

int main()
{
	int n, sum = 0;
	string nums;
	cin >> n >> nums;

	for (int i = 0; i < n; i++)
	{
		sum += (int(nums[i]) - '0');
	}

	cout << sum;

	return 0;
}