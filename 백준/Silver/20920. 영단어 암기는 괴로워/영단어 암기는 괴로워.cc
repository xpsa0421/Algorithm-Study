#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	unordered_map<string, int> wordCounts;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s.length() < m) continue;
		if (wordCounts.find(s) == wordCounts.end())
		{
			wordCounts.emplace(s, 1);
		}
		else wordCounts[s]++;
	}

	// Convert the map into vector of pairs
	vector<pair<string, int>> vec(wordCounts.begin(), wordCounts.end());

	// Custom comparator
	auto comparator = [](const pair<string,int>& a, const pair<string,int>& b){
		if (a.second != b.second)
		{
			return a.second > b.second; // Decreasing order of counts
		}
		if (a.first.length() != b.first.length())
		{
			return a.first.length() > b.first.length(); // Decreasing order of length
		}
		return a.first < b.first; // Alphabetical order
	};

	sort(vec.begin(), vec.end(), comparator);

	for (auto& p : vec)
	{
		cout << p.first << '\n';
	}
}