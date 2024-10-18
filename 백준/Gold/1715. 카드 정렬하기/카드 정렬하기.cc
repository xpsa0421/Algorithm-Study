#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct compare
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, size = 0;
	cin >> n;

	priority_queue<int, vector<int>, compare> deck;
	while (n--)
	{
		cin >> size;
		deck.push(size);
	}

	int ans = 0;
	while (deck.size() > 1)
	{
		int a = deck.top(); deck.pop();
		int b = deck.top(); deck.pop();
		deck.push(a + b);
		ans += a + b;
	}

	cout << ans;
}
