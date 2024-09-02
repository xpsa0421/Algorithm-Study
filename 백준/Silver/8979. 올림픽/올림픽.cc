#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
using namespace std;

bool comparator(const tuple<int, int, int, int>& p1, 
	const tuple<int, int, int, int>& p2)
{
	if (get<1>(p1) == get<1>(p2))
	{
		if (get<2>(p1) == get<2>(p2))
		{
			return get<3>(p1) > get<3>(p2);
		}
		else
		{
			return get<2>(p1) > get<2>(p2);
		}
	}
	else
	{
		return get<1>(p1) > get<1>(p2);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<tuple<int, int, int, int>> info;
	for (int i = 1; i <= n; i++)
	{
		int idx, gold, silver, bronze;
		cin >> idx >> gold >> silver >> bronze;
		info.push_back(make_tuple(idx, gold, silver, bronze));
	}

	sort(info.begin(), info.end(), comparator);

	int prev = 1, cur = 0;
	int pGold = get<1>(info[0]);
	int pSilver = get<2>(info[0]);
	int pBronze = get<3>(info[0]);

	for (int i = 0; i < n; i++)
	{
		int gold = get<1>(info[i]);
		int silver = get<2>(info[i]);
		int bronze = get<3>(info[i]);

		if (i > 0 && (gold != pGold || silver != pSilver || bronze != pBronze))
		{
			prev += cur;
			cur = 0;
		}

		if (get<0>(info[i]) == k)
		{
			cout << prev;
			break;
		}

		pGold = gold;
		pSilver = silver;
		pBronze = bronze;
		cur++;
	}
}