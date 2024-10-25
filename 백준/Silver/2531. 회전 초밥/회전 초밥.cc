#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// Input
	int n, d, k, c;
	cin >> n >> d >> k >> c;
	vector<int> sushi(n);
	for (int i = 0; i < n; i++)
		cin >> sushi[i];

	// 첫번째 경우 (0에서 시작하는 k개의 접시)
	unordered_map<int, int> types; // type, count
	types[c] = 1;
	for (int i = 0; i < k; i++)
		types[sushi[i % n]]++;
	int maxTypes = types.size();
	
	// 나머지 경우 (i에서 시작하는 k개의 접시)
	for (int i = 1; i < n; i++)
	{
		// 새 접시 추가하기
		types[sushi[(i + k - 1) % n]]++;

		// 이전 접시 없애기
		types[sushi[i - 1]]--;
		if (types[sushi[i - 1]] == 0) types.erase(sushi[i - 1]);

		maxTypes = max(maxTypes, (int)types.size());
	}

	cout << maxTypes;
}