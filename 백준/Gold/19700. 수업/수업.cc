#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// Input
	vector<pair<int, int>> students; // height, k
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int h, k;
		cin >> h >> k;
		students.push_back({ h, k });
	}
	sort(students.begin(), students.end(), greater<pair<int, int>>()); // 키 내림차순 정렬

	// Solve - Greedy
	vector<int> teamSizes;
	for (int i = 0; i < n; i++)
	{
		int h = students[i].first, k = students[i].second;
		auto it = upper_bound(teamSizes.begin(), teamSizes.end(), k, greater<int>());
		if (it == teamSizes.end())
			teamSizes.push_back(1);
		else
			(*it)++;
	}

	// Output
	cout << teamSizes.size();
}
