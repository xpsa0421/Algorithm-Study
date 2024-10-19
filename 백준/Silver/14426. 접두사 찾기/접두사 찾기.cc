#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10000 * 500 + 3;
int nxt[MAX][26];
const int root = 1;
int unused = 2;
int n, m;

int c2i(char c)
{
	return c - 'a';
}

void init()
{
	for (int i = 1; i < MAX; i++)
		fill(nxt[i], nxt[i] + 26, -1);
}

void insert(string s)
{
	int cur = root;
	for (char c : s)
	{
		if (nxt[cur][c2i(c)] == -1)
		{
			nxt[cur][c2i(c)] = unused;
			unused++;
		}
		cur = nxt[cur][c2i(c)];
	}
}

bool isPrefix(string s)
{
	int cur = root;
	for (char c : s)
	{
		if (nxt[cur][c2i(c)] == -1)
		{
			return false;
		}
		cur = nxt[cur][c2i(c)];
	}
	return true;
}

int main()
{ 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	init();

	while (n--)
	{
		string s; cin >> s;
		insert(s);
	}

	int ans = 0;
	while (m--)
	{
		string s; cin >> s;
		if (isPrefix(s)) ans++;
	}

	cout << ans;
}
