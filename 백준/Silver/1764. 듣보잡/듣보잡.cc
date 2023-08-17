#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int not_heard, not_seen, not_heard_seen;
	cin >> not_heard >> not_seen;

	vector<string> not_heard_list;
	vector<string> final_list;

	string s;
	while (not_heard--)
	{
		cin >> s;
		not_heard_list.push_back(s);
	}
	sort(not_heard_list.begin(), not_heard_list.end());

	while (not_seen--)
	{
		cin >> s;
		if (binary_search(not_heard_list.begin(), not_heard_list.end(), s))
			final_list.push_back(s);
		else
			continue;
	}
	sort(final_list.begin(), final_list.end());
	
	int final_size = final_list.size();
	cout << final_size << "\n";

	for (auto& pp : final_list)
	{
		cout << pp << "\n";
	}
}