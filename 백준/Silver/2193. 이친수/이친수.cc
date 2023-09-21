#include <iostream>
#include <vector>
#include <queue>
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
	long long total = 1, zeros_count = 0, ones_count = 1;
	for (int i = 1; i < n; i++)
	{
		ones_count = zeros_count;
		zeros_count = total;	
		total = zeros_count + ones_count;
	}
	
	// output
	cout << total;
}
