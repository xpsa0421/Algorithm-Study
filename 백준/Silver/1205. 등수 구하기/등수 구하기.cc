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

	int n, k, p;
	cin >> n >> k >> p;

	vector<int> scores(n);
	for (int i = 0; i < n; i++)
	{
		cin >> scores[i];
	}

	// 내 점수가 유일할 경우 바로 1위 출력
	if (n == 0)
	{
		cout << 1;
		return 0;
	}

	int curRank = 1, ans = -1;
	for (int i = 0; i < n; i++)
	{
		// 내 점수가 더 높을 경우 곧바로 갱신
		if (k > scores[i])
		{
			ans = curRank;
			break;
		}
		else if (k == scores[i])
		{
			for (int j = i + 1; j < n; j++)
			{
				// 그 다음 등수로 넘어갔을 경우
				if (scores[j] != scores[i])
				{
					// 다음 등수가 순위권에 포함될 경우
					if (j < p) ans = curRank;
					break;
				}
			}
			// 마지막까지 검사했고 그 다음 등수가 나오지 않았을 경우
			if (n < p) ans = curRank;
		}
		else
		{
			curRank++;
		}
	}

	// 랭킹 리스트에 여유가 있고 새 점수가 가장 낮은 경우
	if (n < p && ans == -1) ans = n + 1;

	cout << ans;
}