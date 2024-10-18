#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	vector<pair<int, int>> gems;
	multiset<int> maxWeights;
	int n, k;
	cin >> n >> k;

	int m, v, c;
	for (int i = 0; i < n; i++)
	{
		cin >> m >> v;
		gems.push_back({ v, m });
	}
	sort(gems.begin(), gems.end(), greater<pair<int, int>>());
	for (int i = 0; i < k; i++)
	{
		cin >> c;
		maxWeights.insert(c);
	}

	// 가장 가격이 높은 보석부터 확인하여 가장 최대 무게가 적은 가방에 담기
	long long ans = 0;
	for (auto& [price, weight] : gems)
	{
		auto it = maxWeights.lower_bound(weight);
		if (it == maxWeights.end()) continue; // 담을 수 있는 가방이 없음
		ans += price;
		maxWeights.erase(it);
	}

	cout << ans;
}
