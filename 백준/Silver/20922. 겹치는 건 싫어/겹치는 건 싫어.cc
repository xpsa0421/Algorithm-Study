#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];

	int ans = 0, left = 0;
	unordered_map<int, int> cnts;
	for (int right = 0; right < n; right++)
	{
		int num = nums[right];
		if (cnts[num] == k)
		{
			while (true)
			{
				int leftNum = nums[left];
				cnts[leftNum]--;
				left++;
				if (leftNum == num) break;
			}
		}
		cnts[num]++;
		ans = max(ans, right - left + 1);
	}

	cout << ans;
}
