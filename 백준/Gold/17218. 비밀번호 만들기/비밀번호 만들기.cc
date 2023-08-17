#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	vector<vector<int>> lcs(a.length() + 1, vector<int>(b.length() + 1, 0));

	// Fill out lcs table
	for (int i = 1; i < a.length() + 1; i++)
	{
		for (int j = 1; j < b.length() + 1; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else
			{
				lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
			}
		}
	}

	// Find lcs
	string lcs_str = "";
	int i = a.length(), j = b.length();

	while (i != 0 && j != 0)
	{
		if (lcs[i][j] == lcs[i - 1][j])
		{
			i--;
		}
		else if (lcs[i][j] == lcs[i][j - 1])
		{
			j--;
		}
		else
		{
			i--;
			j--;
			lcs_str = a[i] + lcs_str;
		}
	}
	
	cout << lcs_str;
}
