#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int graph[20][20];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int r, c;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 9)
				r = i, c = j;
		}
	}

	// 상, 좌, 우, 하
	int dr[] = { -1,0,0,1 };
	int dc[] = { 0,-1,1,0 };

	int mySize = 2, eaten = 0, totalTime = 0;
	while (true)
	{
		// 초기화
		queue<pair<int, int>> toVisit;
		vector<vector<int>> visitTime(n, vector<int>(n, -1));
		priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> fish;
		int minDist = 1000;
		
		// 시작 위치
		graph[r][c] = 0;
		visitTime[r][c] = 0;
		toVisit.push({ r, c });

		// 물고기 찾기
		while (!toVisit.empty())
		{
			int curR, curC;
			tie(curR, curC) = toVisit.front(); toVisit.pop();

			for (int i = 0; i < 4; i++)
			{
				int nextR = curR + dr[i];
				int nextC = curC + dc[i];
				
				// 지나갈 수 없는 경우
				if (nextR < 0 || nextR == n || nextC < 0 || nextC == n) continue;
				if (visitTime[nextR][nextC] != -1) continue;
				int hisSize = graph[nextR][nextC];
				if (hisSize > mySize) continue;

				// 지나갈 수 있는 경우
				visitTime[nextR][nextC] = visitTime[curR][curC] + 1;
				if (hisSize == 0 || hisSize == mySize)
				{
					toVisit.push({ nextR, nextC });
				}
				// 먹을 수 있는 경우
				else
				{
					if (minDist >= visitTime[nextR][nextC])
					{
						fish.push({ nextR, nextC });
						minDist = visitTime[nextR][nextC];
					}
				}
			}
		}

		// 물고기 먹기
		if (!fish.empty())
		{
			// 크기 증가
			if (++eaten == mySize)
			{
				mySize++;
				eaten = 0;
			}

			// 시간, 시작위치 업데이트
			r = fish.top().first, c = fish.top().second;
			totalTime += visitTime[r][c];

			// 다음 물고기 검색으로 넘어가기
			while (!toVisit.empty()) toVisit.pop();
		}
		else
		{
			break;
		}
	}

	cout << totalTime;
}