#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
#define MAX 0x7f7f7f7f

int n, k;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	vector<int> visited(100005, -1); // 최단 방문 시간
	queue<pair<int,int>> toVisit;
	toVisit.push({n,0});
	visited[n] = 0;

	int minTime = 1000000;
	int count = 0;
	while (!toVisit.empty())
	{
		int curV, curT;
		tie(curV, curT) = toVisit.front();
		toVisit.pop();

		// arrived at k
		if (curV == k)
		{
			if (minTime >= curT)
			{
				minTime = curT;
				count++;
			}
			continue;
		}

		// possible moves
		int nextV[3] = { curV - 1, curV + 1, curV * 2 };
		for (int i = 0; i < 3; i++)
		{
			int next = nextV[i];
			if (next < 0 || next > 100002) continue;
			if (visited[next] == -1 || visited[next] == curT + 1)
			{
				visited[next] = curT + 1;
				toVisit.push({ next, curT + 1 });
			}
		}
	}

	cout << minTime << '\n' << count;
}
