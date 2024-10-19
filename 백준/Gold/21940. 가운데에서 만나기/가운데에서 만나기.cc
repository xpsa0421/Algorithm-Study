#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int times[201][201];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m;

	// Floyd - Initialisation
	for (int i = 1; i <= n; i++)
	{
		fill(times[i], times[i] + n + 1, INF);
		times[i][i] = 0;
	}

	while (m--)
	{
		int a, b, t;
		cin >> a >> b >> t;
		times[a][b] = t;
	}

	cin >> k;
	vector<int> homes(k);
	for (int i = 0; i < k; i++) cin >> homes[i];

	// Floyd - Solve
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (times[i][j] > times[i][k] + times[k][j])
				{
					times[i][j] = times[i][k] + times[k][j];
				}
			}
		}
	}
	
	vector<pair<int, int>> maxTimes; // time, idx
	for (int dst = 1; dst <= n; dst++)
	{
		int maxTime = 0;
		for (int home : homes)
		{
			maxTime = max(maxTime, times[home][dst] + times[dst][home]);
		}
		maxTimes.push_back({ maxTime, dst });
	}

	sort(maxTimes.begin(), maxTimes.end());
	for (int i = 0; i < n; i++)
	{
		if (maxTimes[i].first != maxTimes[0].first) break;
		cout << maxTimes[i].second << ' ';
	}
}
