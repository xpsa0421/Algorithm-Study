#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	queue<int> cards;
	for (int i = 1; i <= n; i++)
	{
		cards.push(i);
	}

	while (cards.size() > 1)
	{
		cards.pop();
		cards.push(cards.front());
		cards.pop();
	}

	cout << cards.front();
}