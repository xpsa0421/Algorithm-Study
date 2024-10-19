#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
#define INF 1e9+10

const int MAX = 500 * 10000 + 5;
int nxt[MAX][26];
bool isLastChar[MAX];
const int root = 1;
int cur = root;
int unused = 2;

int c2i(char c)
{
	return c - 'a';
}

int main()
{ 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < MAX; i++)
	{
		fill(nxt[i], nxt[i] + 26, -1);
	}

	while (n--)
	{
		string s; cin >> s;
		for (char c : s)
		{
			if (nxt[cur][c2i(c)] == -1)
			{
				nxt[cur][c2i(c)] = unused;
				unused++;
			}
			cur = nxt[cur][c2i(c)];
		}
		isLastChar[cur] = true;
		cur = root;
	}

	int included = 0;
	while (m--)
	{
		string s; cin >> s;
		bool isFound = true;
		for (char c : s)
		{
			if (nxt[cur][c2i(c)] == -1)
			{
				isFound = false;
				break;
			}
			cur = nxt[cur][c2i(c)];
		}
		if (isFound && isLastChar[cur]) included++;
		cur = root;
	}

	cout << included;
}
