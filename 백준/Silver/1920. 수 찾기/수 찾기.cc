#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m, num, x;
	set<int> num_set;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		num_set.insert(num);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		cout << (num_set.find(x) != num_set.end()) ? "1" : "0";
		cout << "\n";
	}
}