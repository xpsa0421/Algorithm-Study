#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	priority_queue<int> pq; // max-heap
	priority_queue<int, vector<int>, greater<int>> pqTemp; // min-heap

	int n;
	cin >> n;

	int k;
	for (int i = 0; i < n; i++)
	{
		cin >> k;

		// 현재 max-heap의 최고값보다 내 값이 작다면 max-heap 업데이트
		if (!pq.empty() && pq.top() > k)
		{
			pqTemp.push(pq.top());
			pq.pop();
			pq.push(k);
		}
		// 아니라면 일단 임시 큐에 저장
		else
		{
			pqTemp.push(k);
		}

		if (pq.size() < (i / 2) + 1)
		{
			int nxt = pqTemp.top();
			pqTemp.pop();
			pq.push(nxt);
		}

		cout << pq.top() << '\n';
	}
}
