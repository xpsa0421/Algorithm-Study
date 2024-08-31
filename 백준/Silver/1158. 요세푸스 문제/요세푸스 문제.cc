#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	list<int> ppl;
	for (int i = 1; i <= n; i++) ppl.push_back(i);
	auto it = ppl.begin();

	vector<int> ans;
	ans.reserve(n);

	while (!ppl.empty())
	{
		for (int i = 1; i < k; i++)
		{
			if (it == ppl.end()) it = ppl.begin();
			it++;
		}
		if (it == ppl.end()) it = ppl.begin();
		ans.push_back(*it);
		it = ppl.erase(it);
	}
	cout << '<';
	for (int i = 0; i < n - 1; i++) cout << ans[i] << ", ";
	cout << ans[n - 1] << '>';
}