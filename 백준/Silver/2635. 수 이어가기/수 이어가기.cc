#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int n = 0;
	cin >> n;

	// solve
	int count_max = 0, best = 0;
	for (int i = 1; i <= n; i++)
	{
		int prev_prev = n, prev = i, curr = n - i;
		int count = 2;
		
		while (curr > -1)
		{
			count++;
			prev_prev = prev;
			prev = curr;
			curr = prev_prev - prev;
		}
		
		// update
		if (count_max < count)
		{
			count_max = count;
			best = i;
		}
	}

	// output
	int prev_prev = n, prev = best, curr = n - best;
	cout << count_max << "\n" << prev_prev << " " << prev << " ";
	while (curr > -1)
	{
		cout << curr << " ";
		prev_prev = prev;
		prev = curr;
		curr = prev_prev - prev;
	}
}