#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<int>> nums;
int minusPapers, zeroPapers, plusPapers;

void cut(int stR, int stC, int size)
{
	// count
	int minusCnt = 0, zeroCnt = 0, plusCnt = 0;
	for (int r = stR; r < stR + size; r++)
	{
		for (int c = stC; c < stC + size; c++)
		{
			int num = nums[r][c];
			if (num == -1) minusCnt++;
			else if (num == 0) zeroCnt++;
			else plusCnt++;
		}
	}

	// base condition
	if (zeroCnt == 0)
	{
		if (plusCnt == 0)
		{
			minusPapers++;
			return;
		}
		else if (minusCnt == 0)
		{
			plusPapers++;
			return;
		}
	}
	else if (plusCnt == 0 && minusCnt == 0)
	{
		zeroPapers++;
		return;
	}

	// more cuts
	int cutSize = size / 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cut(stR + cutSize * i, stC + cutSize * j, cutSize);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	nums.resize(n, vector<int>(n,0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> nums[i][j];

	cut(0, 0, n);
	cout << minusPapers << '\n' << zeroPapers << '\n' << plusPapers;
}