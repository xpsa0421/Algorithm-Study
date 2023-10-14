#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	vector<int> needed(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> needed[i];
	}

	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		q.push(i);
	}

	vector<int> times(n, 0);
	vector<bool> inQueue(n, true);
	while (!q.empty())
	{
		int i = q.front();
		needed[i]--;

		for (int i = 0; i < n; i++)
		{
			if (inQueue[i]) times[i]++;
		}

		if (needed[i] > 0) q.push(i);
		else inQueue[i] = false;
		q.pop();
	}
	
	for (int i = 0; i < n; i++)
	{
		cout << times[i] << " ";
	}
}
