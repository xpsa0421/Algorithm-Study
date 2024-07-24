#include <iostream>
#include <vector>
using namespace std;

int Solve(const vector<vector<int>>& vec, int x1, int y1, int x2, int y2);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n,m;
	cin >> n >> m;

	// psum[y,x]는 [0][0]에서 [y][x]까지의 부분합
	vector<vector<int>> psum(n + 1, vector<int>(n + 1, 0));
	int cur;

	for (int y = 0; y <= n; y++)
	{
		for (int x = 0; x <= n; x++)
		{
			if (x == 0 || y == 0)
			{
				psum[y][x] = 0;
			}
			else
			{
				cin >> cur;
				psum[y][x] = psum[y - 1][x]
					+ (psum[y][x - 1] - psum[y - 1][x - 1])
					+ cur;
			}
		}
	}

	vector<int> ans;
	int x1, y1, x2, y2;
	while (m--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		ans.push_back(Solve(psum, y1, x1, y2, x2));
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}
}

int Solve(const vector<vector<int>>& psum, int x1, int y1, int x2, int y2)
{
	int ret = psum[y2][x2]
		- psum[y1 - 1][x2]
		- psum[y2][x1 - 1]
		+ psum[y1 - 1][x1 - 1];
	return ret;
}