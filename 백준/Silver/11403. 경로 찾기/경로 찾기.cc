#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> link(n, vector<int>(n, 101));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;

			if (num == 1)
				link[i][j] = 1;
		}
	}

	for (int mid = 0; mid < n; mid++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				link[i][j] = min(link[i][j], link[i][mid] + link[mid][j]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (link[i][j] == 101) cout << "0 ";
			else cout << "1 ";
		}
		cout << "\n";
	}
}
