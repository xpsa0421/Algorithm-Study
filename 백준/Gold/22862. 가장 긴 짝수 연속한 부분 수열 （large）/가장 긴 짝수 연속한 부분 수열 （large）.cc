#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> nums;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// Input
	int n, k; 
	cin >> n >> k;
	nums.resize(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	// Solve - Two pointers / Sliding window
	int st = 0, en = 0;
	int maxLen = 0, numDels = 0, curLen = 0;
	while (en < n)
	{
		if (nums[en] % 2 == 0)
		{
			curLen++;
		}
		else
		{
			if (numDels == k)
			{
				// 삭제 횟수 복구: 홀수가 나올 때까지 왼쪽 포인터 이동
				maxLen = max(maxLen, curLen);
				while (nums[st] % 2 == 0)
				{
					st++;
					curLen--;
				}
				st++;
			}
			else
			{
				numDels++;
			}
		}
		en++;
	}
	maxLen = max(maxLen, curLen);
	cout << maxLen;
}