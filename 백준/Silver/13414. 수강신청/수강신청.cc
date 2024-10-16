#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int k, l;
	cin >> k >> l;
	unordered_map<string, int> applicants;

	string s;
	for (int i = 0; i < l; i++)
	{
		cin >> s;
		applicants[s] = i;
	}

	vector<pair<string, int>> vec(applicants.begin(), applicants.end());
	sort(vec.begin(), vec.end(),
		[](const pair<string, int>& a, const pair<string, int>& b)
		{
			return a.second < b.second;
		});

	int i = 0;
	for (auto applicant : vec)
	{
		cout << applicant.first << '\n';
		if (++i == k) break;
	}
}
