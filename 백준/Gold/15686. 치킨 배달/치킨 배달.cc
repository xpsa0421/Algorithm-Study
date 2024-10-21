#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
 
// 22
int n, m, minDist = 0x7f7f7f7f;
vector<pair<int, int>> chickPos;
vector<pair<int, int>> homePos;
vector<int> chickIdxs;

void calcDist()
{
	// 집마다 가장 낮은 치킨 거리 저장
	vector<int> chickDistByHome(homePos.size(), 0x7f7f7f7f);
	for (int cIdx : chickIdxs)
	{
		int chickI = chickPos[cIdx].first, chickJ = chickPos[cIdx].second;
		for (int hIdx = 0; hIdx < homePos.size(); hIdx++)
		{
			int homeI = homePos[hIdx].first, homeJ = homePos[hIdx].second;
			int dist = abs(chickI - homeI) + abs(chickJ - homeJ);
			chickDistByHome[hIdx] = min(chickDistByHome[hIdx], dist);
		}
	}

	// 치킨 거리의 총합 업데이트
	int totalDist = 0;
	for (int dist : chickDistByHome) totalDist += dist;
	minDist = min(minDist, totalDist);
}

void search(int i)
{
	if (i == chickPos.size())
	{
		if (chickIdxs.size() == m) calcDist();
		return;
	}

	chickIdxs.push_back(i); search(i + 1);
	chickIdxs.pop_back(); search(i + 1);
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int k; cin >> k;
			if (k == 1) homePos.push_back({ i,j });
			else if (k == 2) chickPos.push_back({ i,j });
		}
	}

	// M개로 이루어진 조합 중 치킨 거리가 가장 작은 경우
	search(0); // consider from idx 0

	cout << minDist;
}
