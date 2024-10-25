#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int duration[10001];
vector<int> adj[10001];
int inDeg[10001];
int endTimes[10001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// Input
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> duration[i];
		int k; cin >> k;
		for (int j = 0; j < k; j++)
		{
			int pre; cin >> pre;
			adj[pre].push_back(i);
		}
		inDeg[i] += k;
	}

	// Solve
	queue<int> task;
	for (int i = 1; i <= n; i++)
	{
		if (inDeg[i] == 0)
		{
			task.push(i);
			endTimes[i] = duration[i];
		}
	}

	while (!task.empty())
	{
		int curV = task.front(); task.pop();
		for (int next : adj[curV])
		{
			if (--inDeg[next] == 0) 
				task.push(next);
			endTimes[next] = max(endTimes[next], endTimes[curV] + duration[next]);
		}
	}

	// Output
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, endTimes[i]);
	cout << ans;
}