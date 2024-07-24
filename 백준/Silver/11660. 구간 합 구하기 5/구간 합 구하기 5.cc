#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n,m;
	cin >> n >> m;

	vector<vector<int>> psum(n + 1, vector<int>(n + 1, 0));
	int cur;

	for (int x = 1; x <= n; x++)
	{
		for (int y = 1; y <= n; y++)
		{
			cin >> cur;
			psum[x][y] = psum[x - 1][y] + (psum[x][y - 1] - psum[x - 1][y - 1]) + cur;
		}
	}

	int x1, y1, x2, y2;
	while (m--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cout << psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] + psum[x1 - 1][y1 - 1] << '\n';
	}
}