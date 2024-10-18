#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

bool finished = false;
int endNode;
int ans;
int tree[100001][2]; // left, right
bool visited[100001];

void dfs(int cur)
{
	int left = tree[cur][0];
	int right = tree[cur][1];

	if (left != -1 && !visited[left])
	{
		ans++;
		visited[left] = true;
		dfs(left);
	}
	if (right != -1 && !visited[right])
	{
		ans++;
		visited[right] = true;
		dfs(right);
	}
	if (cur == endNode)
	{
		finished = true;
		return;
	}
	else if (!finished) ans++;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		tree[a][0] = b;
		tree[a][1] = c;
	}

	// 끝 노드 찾기
	endNode = 1;
	while (tree[endNode][1] != -1)
	{
		endNode = tree[endNode][1];
	}

	visited[1] = true;
	dfs(1);
	cout << ans;
}
