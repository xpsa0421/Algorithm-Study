#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;

		vector<int> a(n,0);
		vector<int> b(m,0);
		for (int i = 0; i < n ; i++) cin >> a[i];
		for (int i = 0; i < m ; i++) cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int eaten = 0, totalEaten = 0;
		int bIdx = 0;
		for (int i = 0; i < n; i++)
		{
			// 이미 가장 큰 B까지 다 먹었다면
			// 이전 a와 크기가 같은 a라면
			if (bIdx == m || (i != 0 && a[i] == a[i - 1]))
			{
				totalEaten += eaten;
				continue;
			}

			// 이전 a와 크기가 다른 a라면
			while (b[bIdx] < a[i])
			{
				eaten++;
				bIdx++;
				if (bIdx == m) break;
			}
			totalEaten += eaten;
		}

		cout << totalEaten << '\n';
	}
}
