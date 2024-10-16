#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	vector<string> applicants;
	unordered_multiset<string> ms;
	unordered_set<string> unique;

	int k, l;
	string s;
	cin >> k >> l;

	while (l--)
	{
		cin >> s;
		applicants.push_back(s);
		ms.insert(s);
		unique.insert(s);
	}

	// multiset에 중복 지원만 남도록 함
	for (string uni : unique)
	{
		ms.erase(ms.find(uni));
	}

	for (string ap : applicants)
	{
		// 중복 지원이 없으면
		auto it = ms.find(ap);
		if (it == ms.end())
		{
			if (k == 0) break;
			k--;
			cout << ap << '\n';
		}
		else
		{
			ms.erase(it);
		}
	}
}