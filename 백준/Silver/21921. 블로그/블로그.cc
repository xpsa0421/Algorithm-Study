#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int x = 0, n = 0;
	cin >> n >> x;

	vector<int> visitors(n);
	for (int i = 0; i < n; i++) cin >> visitors[i];

	int maxVisits = 0, counts = 0, curVisits = 0;

	// Initial X days
	for (int i = 0; i < x; i++)
	{
		curVisits += visitors[i];
	}
	maxVisits = curVisits;
	counts = 1;

	// Sliding Window
	for (int i = x; i < n; i++)
	{
		// new visits
		curVisits -= visitors[i - x];
		curVisits += visitors[i];

		// is it max?
		if (curVisits == maxVisits)
		{
			counts++;
		}
		else if (curVisits > maxVisits)
		{
			maxVisits = curVisits;
			counts = 1;
		}
	}

	// Output
	if (maxVisits == 0) cout << "SAD";
	else cout << maxVisits << '\n' << counts;
}