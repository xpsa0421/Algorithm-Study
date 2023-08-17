#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> list(n);

	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}
	sort(list.begin(), list.end(), [](int a, int b) { return a < b; });

	int total = 0, prev_total = 0;
	for (int i = 0; i < n; i++)
	{
		prev_total += list[i];
		total += prev_total;
	}
	
	cout << total << "\n";
}