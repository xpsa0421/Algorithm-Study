#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
 
// 02:55
vector<vector<int>> party;
int parents[51];

int find(int n)
{
	if (parents[n] < 0) return n;
	else return parents[n] = find(parents[n]);
}

bool merge(int x, int y)
{
	x = find(x), y = find(y);
	if (x == y) return false;
	if (parents[x] == parents[y]) parents[x]--;
	if (parents[x] < parents[y]) parents[y] = x;
	else parents[x] = y;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// 진실을 아는 사람이 있는 파티에 과장 X
	// 해당 파티에 있는 모두가 참가한 파티에 과장 X
	int n, m;
	cin >> n >> m;

	// 처음부터 비밀을 알고 있는 사람 추가
	// 비밀을 아는 트리의 루트를 0
	fill(parents, parents + n + 1, -1);
	int numTruth; cin >> numTruth;
	for (int i = 0; i < numTruth; i++)
	{
		int k; cin >> k;
		merge(0, k);
	}

	// 비밀 아는 사람들의 트리
	// 그 외 사람들이 추가될 때 머지되면 안됨
	party.resize(m);
	for (int i = 0; i < m; i++)
	{
		int k;  cin >> k; k--;
		int rt; cin >> rt; // first person, i.e. root
		party[i].push_back(rt);

		while (k--)
		{
			int p;  cin >> p;
			party[i].push_back(p);
			merge(rt, p);
		}
	}

	if (numTruth == 0)
	{
		cout << m;
		return 0;
	}

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		bool canLie = true;
		for (int p : party[i])
		{
			if (find(p) == find(0))
			{
				canLie = false;
				break;
			}
		}
		if (canLie) ans++;
	}

	cout << ans;
}
