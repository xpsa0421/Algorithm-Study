#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int cases, n, k, t, m;
	int i, j, s;
	cin >> cases;

	while (cases--)
	{
		cin >> n >> k >> t >> m;
		vector<vector<pair<int, int>>> scoresByQ(k + 1);
		
		// 문제별로 팀별 최고점을 기록하는 벡터
		vector<vector<int>> highestScores(k + 1, vector<int>(n + 1, 0));

		// 팀별 제출횟수 벡터
		vector<int> numSubmits(n + 1, 0);

		// 팀별 마지막 제출시간 벡터
		vector<int> lastSubmitTimes(n + 1, 0);

		// 총 점수를 기록하는 맵 (팀번호, 총점)
		map<int, int> totalScoresM;
		for (int team = 1; team <= n; team++)
		{
			totalScoresM.emplace(team, 0);
		}

		// 최고점 기록
		for (int time = 0; time < m; time++)
		{
			// 새로 제출한 점수가 더 높다면 갱신
			cin >> i >> j >> s;
			if (highestScores[j][i] < s)
			{
				int curTot = totalScoresM[i];
				curTot -= highestScores[j][i];
				highestScores[j][i] = s;
				totalScoresM[i] = curTot + s;
			}

			// 제출횟수 및 제출시간 갱신
			numSubmits[i]++;
			lastSubmitTimes[i] = time;
		}

		// 우리팀의 점수는?
		int myScore = totalScoresM[t];

		// 총 점수 맵 내림차순 정렬
		vector<pair<int, int>> totalScores(totalScoresM.begin(), totalScoresM.end());
		std::sort(totalScores.begin(), totalScores.end(),
			[](const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second; });

		auto it = lower_bound(totalScores.begin(), totalScores.end(), make_pair(0, myScore),
			[](const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second; });
		int ans = it - totalScores.begin() + 1;

		// 중복이 있는가?
		for (auto itr = it; itr != totalScores.end(); itr++)
		{
			// 다른 점수면 바로 리턴
			if ((*itr).second != myScore) break;

			// 같은 점수의 다른 팀이라면 비교
			int team = (*itr).first;
			if (team != t)
			{
				// 풀이 횟수가 적다면 우리 팀보다 앞선다
				// 풀이 횟수가 같고 마지막 제출 시간이 빠르다면 우리 팀보다 앞선다
				if (numSubmits[team] < numSubmits[t]
					|| (numSubmits[team] == numSubmits[t] && lastSubmitTimes[team] < lastSubmitTimes[t]))
					ans++;
			}
		}
		
		cout << ans << '\n';
	}
}