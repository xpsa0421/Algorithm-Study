#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	int num;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n * n; i++)
	{
		cin >> num;
		pq.push(num);

		// n개를 넘어가면 가장 작은 값 제거
		if (pq.size() > n) pq.pop();
	}

	cout << pq.top();
}