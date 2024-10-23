#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int chosen[100001];
bool visited[100001];
bool handled[100001];
int cnt;

// visited된 위치로 되돌아오면 cycle, 즉 팀이다
void dfs(int cur)
{
	visited[cur] = true;
	int next = chosen[cur];

	if (!visited[next])
	{
		dfs(next);
	}
	else if (!handled[next])
	{
		// 팀을 이루는 경우
		for (int i = next; i != cur; i = chosen[i])
		{
			handled[i] = true;
			cnt++;
		}
		cnt++; // for myself
	}
	handled[cur] = true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> chosen[i];
		}

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i]) dfs(i);
		}

		cout << n - cnt << '\n';

		memset(visited, false, sizeof(visited));
		memset(handled, false, sizeof(handled));
		cnt = 0;
	}
}