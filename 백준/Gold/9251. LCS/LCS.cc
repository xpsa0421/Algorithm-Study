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

	int max_len = 0;
	vector<vector<int>> lcs(a.length() + 1, vector<int>(b.length() + 1, 0));

	for (int a_idx = 1; a_idx <= a.length(); a_idx++)
	{
		for (int b_idx = 1; b_idx <= b.length(); b_idx++)
		{
			if (a[a_idx - 1] == b[b_idx - 1])
			{
				lcs[a_idx][b_idx] = lcs[a_idx - 1][b_idx - 1] + 1;
				max_len = max(max_len, lcs[a_idx][b_idx]);
			}
			else
			{
				lcs[a_idx][b_idx] = max(lcs[a_idx - 1][b_idx], lcs[a_idx][b_idx - 1]);
			}
		}
	}

	cout << max_len;
}