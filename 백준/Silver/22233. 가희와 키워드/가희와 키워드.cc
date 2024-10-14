#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	string word;
	unordered_set<string> keywords;
	while (n--)
	{
		cin >> word;
		keywords.insert(word);
	}

	string text;
	while (m--)
	{
		cin >> text;
		size_t start = 0, end = 0;

		// Words extraction
		vector<string> words;
		while ((end = text.find(',', start)) != string::npos)
		{
			words.push_back(text.substr(start, end - start));
			start = end + 1;
		}
		words.push_back(text.substr(start));

		// Keyword comparison
		for (string w : words)
		{
			if (keywords.find(w) != keywords.end())
			{
				keywords.erase(w);
				if (keywords.empty()) break;
			}
		}

		// Remaining keywords
		cout << keywords.size() << '\n';
	}
}