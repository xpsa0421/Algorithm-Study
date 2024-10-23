#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int scores[100];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> scores[i];

	int decreaseCnt = 0;
	// 마지막에서 두번째 레벨부터 앞에서 첫번째 레벨까지
	for (int i = n - 2; i >= 0; i--)
	{
		// 다음 레벨 점수보다 높거나 같다면 현 레벨의 점수 낮추기
		if (scores[i] >= scores[i + 1])
		{
			decreaseCnt += (scores[i] - scores[i + 1]) + 1;
			scores[i] = scores[i + 1] - 1;
		}
	}

	cout << decreaseCnt;
}