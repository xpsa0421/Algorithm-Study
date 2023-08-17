#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> nums(n*2);

	for (int i = 0; i < n * 2; i++)
	{
		cin >> nums[i];
	}

	for (int i = 0; i < n * 2; i = i + 2)
	{
		cout << nums[i] + nums[i + 1] << endl;
	}

	return 0;
}