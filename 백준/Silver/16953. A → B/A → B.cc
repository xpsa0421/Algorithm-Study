#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;

	queue<long long> toVisit;
	queue<int> numVisits;
	set<long long> visited;

	toVisit.push(a);
	numVisits.push(1);
	while (!toVisit.empty())
	{
		int numVisit = numVisits.front();
		long long cur = toVisit.front();
		toVisit.pop();
		numVisits.pop();
		
		if (visited.find(cur) != visited.end()) continue;
		visited.insert(cur);

		if (cur == b)
		{
			cout << numVisit;
			return 0;
		}
		else if (cur > b)
		{
			continue;
		}

		toVisit.push(cur * 2);
		toVisit.push(cur * 10 + 1);
		numVisits.push(numVisit + 1);
		numVisits.push(numVisit + 1);
	}

	cout << -1;
}