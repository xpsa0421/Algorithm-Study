#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int n, max = 0;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &nums[i]);
		if (nums[i] > max) max = nums[i];
	}

	double total = 0;
	for (int& num : nums)
	{
		double new_score = double(num) / max * 100;
		total += new_score;
	}

	printf("%f", total / n);
	return 0;
}