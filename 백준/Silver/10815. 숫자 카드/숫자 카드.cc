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
	vector<int> cards(n, 0);
	for (int i = 0; i < n; i++) cin >> cards[i];

	int m = 0;
	cin >> m;
	vector<int> tests(m, 0);
	for (int i = 0; i < m; i++) cin >> tests[i];
	
	// solve
	sort(cards.begin(), cards.end());

	for (int test : tests)
	{
		auto iter = lower_bound(cards.begin(), cards.end(), test);
		cout << (iter == cards.end() || *iter != test ? "0 " : "1 ");
	}
}
