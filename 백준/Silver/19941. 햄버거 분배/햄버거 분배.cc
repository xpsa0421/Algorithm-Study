#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	string table;
	cin >> table;

	queue<int> nextHIndices;
	queue<int> nextPIndices;
	int ans = 0;
	bool eaten = false;
	
	for (int i = 0; i < n; i++)
	{
		eaten = false;

		if (table[i] == 'H')
		{
			// 새로운 햄버거가 들어오면, 이전 사람들이 먹을 수 있는지
			while (!nextPIndices.empty())
			{
				// 가장 멀리 있는 사람부터 비교
				int PIdx = nextPIndices.front();
				nextPIndices.pop();

				// 먹을 수 있다면 다음 자리로 이동
				if (i - PIdx <= k)
				{
					ans++;
					eaten = true;
					break;
				}
			}
			// 이전 사람들이 먹을 수 없다면 햄버거 대기
			if (!eaten) nextHIndices.push(i);
		}
		// 다음 자리가 사람일 경우
		else
		{
			// 대기중인 햄버거중에 먹을 게 있는지
			while (!nextHIndices.empty())
			{
				// 가장 멀리 있는 햄버거부터 비교
				int hIdx = nextHIndices.front();
				nextHIndices.pop();

				// 먹을 수 있다면 다음 자리로 이동
				if (i - hIdx <= k)
				{
					ans++;
					eaten = true;
					break;
				}
			}
			// 대기중인 햄버거를 먹을 수 없다면 사람 대기
			if (!eaten) nextPIndices.push(i);
		}
	}

	cout << ans;
}