#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// 조카 M명에게 똑같이 나눠줄 수 있는 과자의 최대 길이
	int m, n;
	cin >> m >> n;

	vector<int> lens(n, 0);
	for (int i = 0; i < n; i++) cin >> lens[i];
	sort(lens.begin(), lens.end());

	// 과자의 목표 길이가 짧을수록 더 많은 사람에게 줄 수 있음
	// M명 이상에게 줄 수 있는 최대의 길이
	int start = 1, end = lens[n-1], mid = 0;
	while (start <= end)
	{
		// 몇 명이 나눠먹을 수 있는가?
		mid = (end + start) / 2;
		int cnt = 0;
		for (int len : lens)
		{
			cnt += len / mid;
		}

		// cnt가 m 이상이면서 mid가 가장 큰 경우를 찾아야 함
		if (cnt < m) end = mid - 1;
		else start = mid + 1;
	}

	cout << end;
}