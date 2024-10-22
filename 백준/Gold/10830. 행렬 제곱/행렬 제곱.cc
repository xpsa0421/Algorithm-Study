#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
#define MAX 0x7f7f7f7f

int n, mod = 1000;
vector<vector<int>> ori;

vector<vector<int>> multiply(vector<vector<int>> a, vector<vector<int>> b)
{
	vector<vector<int>> res(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				res[i][j] += a[i][k] * b[k][j];
				res[i][j] %= 1000;
			}
		}
	}
	return res;
}

vector<vector<int>> power(long long exp)
{
	if (exp == 1)
	{
		return ori;
	}
	if (exp % 2 == 0)
	{
		vector<vector<int>> res = power(exp / 2);
		return multiply(res, res);
	}
	else
	{
		vector<vector<int>> res = power(exp - 1);
		return multiply(ori, res);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long b;
	cin >> n >> b;

	ori.resize(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> ori[i][j];
			ori[i][j] %= 1000;
		}
	}

	vector<vector<int>> res = power(b);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << res[i][j] << ' ';
		}
		cout << '\n';
	}			
}
