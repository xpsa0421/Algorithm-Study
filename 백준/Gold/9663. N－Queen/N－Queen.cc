#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
bool isUsedY[15];
bool isUsedLD[30];
bool isUsedRD[30];

void solve(int k)
{
	if (k == n)
	{
		ans++;
		return;
	}

	// k row의 i column
	for (int i = 0; i < n; i++)
	{
		if (!isUsedY[i] && !isUsedLD[k + i] && !isUsedRD[k - i + n - 1])
		{
			isUsedY[i] = isUsedLD[k + i] = isUsedRD[k - i + n - 1] = true;
			solve(k + 1);
			isUsedY[i] = isUsedLD[k + i] = isUsedRD[k - i + n - 1] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;
	solve(0);

	cout << ans;
}