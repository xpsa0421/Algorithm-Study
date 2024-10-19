#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

const int MAX = 10000 * 10 + 3;
int nxt[MAX][10];
bool isLastNum[MAX];
const int root = 1;
int unused = 2;

int c2i(char c)
{
	return c - '0';
}

void init()
{
	for (int i = 1; i < MAX; i++)
		fill(nxt[i], nxt[i] + 10, -1);
	fill(isLastNum, isLastNum + MAX, false);
	unused = 2;
}

void insert(string s)
{
	int cur = root;
	for (char c : s)
	{
		if (nxt[cur][c2i(c)] == -1)
			nxt[cur][c2i(c)] = unused++;
		cur = nxt[cur][c2i(c)];
	}
	isLastNum[cur] = true;
}

bool hasPrefix()
{
	queue<int> toVisit;
	toVisit.push(root);

	while (!toVisit.empty())
	{
		int cur = toVisit.front();
		toVisit.pop();

		for (int i = 0; i < 10; i++)
		{
			if (nxt[cur][i] == -1) continue;
			if (isLastNum[cur]) return true;
			toVisit.push(nxt[cur][i]);
		}
	}
	return false;
}

int main()
{ 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;

	while (t--)
	{
		init();
		int n; cin >> n;
		while (n--)
		{
			string s; cin >> s;
			insert(s);
		}
		cout << (hasPrefix() ? "NO\n" : "YES\n");
	}
}
