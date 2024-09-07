#include <iostream>
#include <algorithm>
#include <vector>
#include<math.h>
#include<map>
#include<memory.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> dists(n-1);
	vector<int> prices(n);
	for (int i = 0; i < n - 1; i++) cin >> dists[i];
	for (int i = 0; i < n; i++) cin >> prices[i];

	int total = 0, curCity = 0;
	while (curCity < n - 1)
	{
		// 다음으로 기름값이 싼 곳까지 이동
		int dest = 0, dist = 0;
		for (int c = curCity + 1; c < n; c++)
		{
			// 이동
			dist += dists[c - 1];
			dest = c;

			// C의 기름값이 더 쌀 경우 멈춤
			if (prices[c] < prices[curCity]) break;
		}

		// 총 기름값 업데이트
		total += dist * prices[curCity];

		// 위치 갱신
		curCity = dest;
	}

	cout << total;
}