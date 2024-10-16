#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	int i = 2, cur = n;
	while (i * i <= cur)
	{
		if (cur % i == 0)
		{
			cout << i << '\n';
			cur /= i;
		}
		else i++;
	}
	if (cur > 1) cout << cur << '\n';
}
