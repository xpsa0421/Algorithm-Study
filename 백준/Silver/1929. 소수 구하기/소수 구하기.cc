#include <iostream>
#include <vector>
#include <cmath>
#include <memory.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int m, n;
	cin >> m >> n;

	bool checklist[1000001];
	memset(checklist, true, sizeof(checklist));
	checklist[1] = false;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (!checklist[i]) continue;

		int j = 2;
		while (i * j <= n)
		{
			checklist[i * j] = false;
			j++;
		}
	}

	for (int i = m; i <= n; i++)
	{
		if (checklist[i]) cout << i << "\n";
	}
}