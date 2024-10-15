#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int n, m;
int cnts[300001];

// 질투심이 mid라면 N명 이하의 학생에게 나누어 줄 수 있는가?
bool check(int mid)
{
	int s = 0;
	for (int i = 0; i < m; i++)
	{
		int q = cnts[i] / mid;
		int r = cnts[i] % mid;
		if (r != 0) s += q + 1;
		else s += q;
	}
	return s <= n;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	int st = 0, en = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> cnts[i];
		en = max(en, cnts[i]);
	}
	en++;

	// 목표: 학생의 수 N 이하로 나올 수 있는 질투심의 최솟값
	// 질투심의 범위: [1, max(cnts)]
	// 질투심을 '매개변수'로 한 매개 변수 탐색
	// TTT.....FFFF
	while (st + 1 < en)
	{
		int mid = (st + en) / 2;
		if (check(mid)) en = mid;
		else st = mid;
	}

	cout << en;
}