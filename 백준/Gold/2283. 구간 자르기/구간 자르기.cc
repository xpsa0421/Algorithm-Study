#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	int maxEn = 0;
	vector<int> sum(1000001, 0);
	for (int i = 0; i < n; i++)
	{
		int st, en;
		cin >> st >> en;
		for (int i = st; i < en; i++)
			sum[i]++;
		maxEn = max(en, maxEn);
	}

	int st = 0, en = 0, cur = 0;
	while (st <= en)
	{
		if (cur == k)
		{
			cout << st << ' ' << en;
			return 0;
		}

		if (cur < k)
		{
			cur += sum[en++];
			if (en > maxEn) break;
		}
		else
		{
			cur -= sum[st++];
		}
	}

	cout << "0 0";
}