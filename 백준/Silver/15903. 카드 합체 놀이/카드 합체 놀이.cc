#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	long long sum = 0;
	priority_queue<long long, vector<long long>, greater<long long>> cards;
	for (int i = 0; i < n; i++)
	{
		int num; cin >> num;
		cards.push(num);
		sum += num;
	}

	while (m--)
	{
		long long a = cards.top(); cards.pop();
		long long b = cards.top(); cards.pop();
		cards.push(a + b);
		cards.push(a + b);
		sum += a + b;
	}

	std::cout << sum;
}