#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// Input
	// Button: 300, 60, 10 seconds
	int t; cin >> t;
	
	// Solve
	int a = 0, b = 0, c = 0;
	if (t / 300 > 0)
	{
		a = t / 300;
		t %= 300;
	}
	if (t / 60 > 0)
	{
		b = t / 60;
		t %= 60;
	}
	c = t / 10;
	t %= 10;

	// Output
	if (t != 0) cout << -1;
	else cout << a << ' ' << b << ' ' << c;
}