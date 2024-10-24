#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> homes;
int n, c;

bool check(int minDist)
{
	// Suppose the first house is fixed
	int cnt = 1, prev = homes[0];
	for (int i = 1; i < n; i++)
	{
		if (homes[i] - prev >= minDist)
		{
			cnt++;
			prev = homes[i];
		}
	}
	return cnt >= c;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	homes.resize(n, 0);
	for (int i = 0; i < n; i++) cin >> homes[i];
	sort(homes.begin(), homes.end());

	// 가장 인접한 거리가 x일때, 공유기를 C개 이상 설치할 수 있는가?
	// TTT....FFF
	int st = 1, en = homes.back() - homes[0] + 1;
	while (st + 1 < en)
	{
		int mid = (st + en) / 2;
		if (check(mid))	st = mid;
		else en = mid;
	}

	cout << st;
}