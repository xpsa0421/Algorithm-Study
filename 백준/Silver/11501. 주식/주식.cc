#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// 오늘부터 마지막 날까지중 가장 높은 주식 가격을 기록
	// 오늘의 주식 가격이 남은 날 중 가장 높은 가격이라면 전부 판매
	// 오늘의 주식 가격이 가장 높지 않다면 구매

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		// 주식 가격 기록
		vector<int> prices(n, 0);
		for (int i = 0; i < n; i++) cin >> prices[i];

		vector<int> highests(n, 0);
		highests[n - 1] = prices[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			highests[i] = max(highests[i + 1], prices[i]);
		}

		int count = 0; // 주식보유개수
		long long buy = 0, sell = 0; // 구매금, 판매금
		for (int i = 0; i < n; i++)
		{
			// 오늘이 가장 비싸면 다 판매
			if (highests[i] == prices[i])
			{
				sell += prices[i] * count;
				count = 0;
			}
			// 아니면 하나 구매
			else
			{
				buy += prices[i];
				count++;
			}
		}

		cout << sell - buy << '\n';
	}
}