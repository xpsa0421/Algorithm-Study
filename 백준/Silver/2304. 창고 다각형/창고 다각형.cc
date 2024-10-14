#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// 맨 앞에서 시작해서 오른쪽으로 탐색
	// 나보다 높은 기둥이 있다면, 해당 기둥 탐색 후 그 높이까지 이동 (내 높이로)
	// 나보다 높은 기둥이 없다면, 남은 기둥 중 가장 높은 기둥까지 이동 (그 기둥의 높이로)

	int n;
	cin >> n;

	// 기둥 높이 인풋 받기 (position, height)
	int pos, height;
	vector<pair<int, int>> towers; 
	for (int i = 0; i < n; i++)
	{
		cin >> pos >> height;
		towers.emplace_back(pos, height);
	}

	// 위치순 정렬
	sort(towers.begin(), towers.end());

	int ans = 0, t = 0;
	while (t != n - 1)
	{
		int h = towers[t].second;

		int nextHighest = 0, nextHIdx;
		for (int next = t + 1; next < n; next++)
		{
			// 가장 높은 타워 갱신
			int curH = towers[next].second;
			if (nextHighest < curH)
			{
				nextHighest = curH;
				nextHIdx = next;

				// 지금 타워보다 높다면 그만 검색하고 넓이 갱신
				if (curH > h)
				{
					ans += h * (towers[next].first - towers[t].first);
					t = next;
					break;
				}
			}
		}

		// 지금 타워보다 높은 타워가 없다면 높이를 내리고 2nd highest까지 이동
		if (nextHighest <= h)
		{
			ans += h;
			ans += nextHighest * (towers[nextHIdx].first - towers[t].first - 1);
			t = nextHIdx;
		}
	}
	ans += towers[n - 1].second;
	cout << ans;
}