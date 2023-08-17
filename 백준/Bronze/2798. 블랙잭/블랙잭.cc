#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &nums[i]);
	}

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (nums[i] + nums[j] + nums[k] <= m)
				{
					res = max(nums[i] + nums[j] + nums[k], res);
				}
			}
		}
	}

	printf("%d", res);
	return 0;
}
