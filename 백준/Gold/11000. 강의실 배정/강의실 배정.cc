#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int n = 0;
	cin >> n;
	vector<pair<int, int>> classes;
	for (int i = 0; i < n; i++)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		classes.push_back(make_pair(start, end));
	}

	// solve
	sort(classes.begin(), classes.end());
	
	priority_queue<int, vector<int>, greater<int>> endtimes;
	endtimes.push(classes[0].second);
	for (int i = 1; i < n; i++)
	{
		int starttime = classes[i].first;
		int endtime = classes[i].second;

		if (starttime >= endtimes.top())
		{
			endtimes.pop();
		}
		endtimes.push(endtime);
	}
	
	// output
	std::cout << endtimes.size();
}