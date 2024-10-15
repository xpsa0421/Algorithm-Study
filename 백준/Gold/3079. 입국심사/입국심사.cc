#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
using namespace std;

int n, m;
int times[100001];

// mid초 내에 m명이 심사받을 수 있는가?
bool check(long long mid)
{
	long long t = 0;
	// mid 초 내에 심사 가능한 최대 승객 수
	for (int i = 0; i < n; i++)
	{
		t += mid / times[i];
		if (t >= m) return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> times[i];

	long long st = 0, en = *min_element(times, times + n) * static_cast<long long>(m) + 1;
	while (st + 1 < en)
	{
		long long mid = (st + en) / 2;
		if (check(mid)) en = mid;
		else st = mid;
	}

	cout << en;
}