#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<pair<int,int>> coords(n + 1);
	for (int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		coords[i] = { x,y };
	}
	coords[n] = coords[0];

	// Shoelace theorem
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += ((long long)coords[i].first * coords[i + 1].second) -
			((long long)coords[i].second * coords[i + 1].first);
	}
	double area = abs(sum) / 2.0;
	cout << fixed << setprecision(1) << area;
}