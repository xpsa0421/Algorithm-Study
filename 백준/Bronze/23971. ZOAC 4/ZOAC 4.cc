#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	float h = 0, w = 0, n = 0, m = 0;
	cin >> h >> w >> n >> m;

	// solve
	int one_row = ceil(h / (n + 1));
	int one_col = ceil(w / (m + 1));
	int ans = one_row * one_col;

	// output
	cout << ans;
}
