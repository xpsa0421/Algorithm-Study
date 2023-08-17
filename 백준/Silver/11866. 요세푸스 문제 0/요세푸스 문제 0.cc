#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	queue<int> players;
	vector<int> sequence;
	for (int i = 1; i <= n; i++)
	{
		players.push(i);
	}

	while (players.size() > 0)
	{
		for (int i = 1; i < k; i++)
		{
			players.push(players.front());
			players.pop();
		}
		sequence.push_back(players.front());
		players.pop();
	}

	cout << "<";
	for (int i = 0; i < n-1; i++)
	{
		cout << sequence[i] << ", ";
	}
	cout << sequence[n-1] << ">";
}