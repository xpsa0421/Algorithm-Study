#include <iostream>
#include <algorithm>
#include <vector>
#include<math.h>
#include<map>
#include<memory.h>
using namespace std;

int counts[201];
int scoreCounts[201];
int sum[201][2];
vector<int> scores;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int t, n;
	cin >> t;
	
	while (t--)
	{
		memset(counts, 0, sizeof(counts));
		memset(scoreCounts, 0, sizeof(scoreCounts));
		memset(sum, 0, sizeof(sum));
		scores.clear();
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			int team; cin >> team;
			counts[team]++;
			scores.push_back(team);
		}

		int score = 1;
		for (int team : scores)
		{
			if (counts[team] == 6)
			{
				scoreCounts[team]++;
				if (scoreCounts[team] < 5)
				{
					sum[team][0] += score;
				}
				else if (scoreCounts[team] == 5)
				{
					sum[team][1] = score;
				}
				score++;
			}
		}

		int ans = 1, winScore = 99999999;
		for (int i = 1; i <= 200; i++)
		{
			if (counts[i] != 6) continue;
			if (sum[i][0] < winScore)
			{
				winScore = sum[i][0];
				ans = i;
			}
			else if (sum[i][0] == winScore)
			{
				if (sum[i][1] < sum[ans][1]) ans = i;
			}
		}

		cout << ans << '\n';
	}
}