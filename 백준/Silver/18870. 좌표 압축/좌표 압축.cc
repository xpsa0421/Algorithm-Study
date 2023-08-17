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

	vector<int> coords_all;
	vector<int> coords_unique;

	while (n--)
	{
		int x;
		cin >> x;
		coords_all.push_back(x);
		coords_unique.push_back(x);
	}

	sort(coords_unique.begin(), coords_unique.end());
	coords_unique.erase(unique(coords_unique.begin(), coords_unique.end()), coords_unique.end());

	for (auto& coord : coords_all)
	{
		int compressed = lower_bound(coords_unique.begin(), coords_unique.end(), coord) - coords_unique.begin();
		cout << compressed << " ";
	}
}