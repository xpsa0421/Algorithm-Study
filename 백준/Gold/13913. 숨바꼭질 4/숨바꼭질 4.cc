#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int n = 0, k = 0;
	cin >> n >> k;

	// solve
	vector<bool> visited(100001, false);
	vector<int> prevs(100001, -1);
	queue<int> to_visit;
	to_visit.emplace(n);
	visited[n] = true;

	while (!to_visit.empty())
	{
		int curr = to_visit.front();
		to_visit.pop();
		vector<int> nexts;
		if (curr > k) nexts = { curr - 1 };
		else nexts = { curr * 2, curr - 1, curr + 1 };

		for (int next : nexts)
		{
			if (next < 0 || next > 100000) continue;
			if (visited[next]) continue;
			if (next == k)
			{
				prevs[k] = curr;
				goto end;
			}
			else
			{
				prevs[next] = curr;
				to_visit.push(next);
				visited[next] = true;
			}
		}
	}

end:
	int time = 0;
	stack<int> ans;
	ans.push(k);
	int next = k;
	while (next != n)
	{
		next = prevs[next];
		ans.push(next);
		time++;
	}

	// output
	cout << time << '\n';
	while (!empty(ans))
	{
		cout << ans.top() << " ";
		ans.pop();
	}
}