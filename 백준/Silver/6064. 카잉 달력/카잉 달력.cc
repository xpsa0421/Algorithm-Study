#include <iostream>
#include <numeric>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int t, m, n, x, y;
	cin >> t;

	while (t--)
	{
		cin >> m >> n >> x >> y;
		int curr_x = x;
		int curr_y = (x % n == 0) ? n : x % n;
		int count = x;
		int last = lcm(m, n);
		
		while (count <= last)
		{
			if (curr_x == x && curr_y == y) break;
			count += m;
			curr_y = count % n;
			if (curr_y == 0) curr_y = n;
		}
		if (count > last)
		{
			cout << -1 << "\n";
		}
		else cout << count << "\n";
	}
}