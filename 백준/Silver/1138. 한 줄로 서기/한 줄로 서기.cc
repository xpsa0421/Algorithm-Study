#include <iostream>
#include <vector>
using namespace std;

int ans[10];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	int toMove = 0, pos;
	for (int i = 1; i <= n; i++)
	{
		pos = 0;
		cin >> toMove;
		while (toMove > 0)
		{
			if (ans[pos] == 0) toMove--;
			pos++;
		}
		while (ans[pos] != 0) pos++;
		ans[pos] = i;
	}

	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}
