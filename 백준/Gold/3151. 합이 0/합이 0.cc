#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	vector<int> scores(n, 0);
	for (int i = 0; i < n; i++)
		cin >> scores[i];

	long long ans = 0;
	sort(scores.begin(), scores.end());
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int target = -(scores[i] + scores[j]);
			auto lower = lower_bound(scores.begin() + j + 1, scores.end(), target) - scores.begin();
			auto upper = upper_bound(scores.begin() + j + 1, scores.end(), target) - scores.begin();
			ans += upper - lower;
		}
	}

	cout << ans;
}