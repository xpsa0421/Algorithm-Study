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

	int n; cin >> n;
	
	// 음수, 양수 따로 저장. 0은 카운트.
	vector<int> neg;
	vector<int> pos;
	int zeroCnt = 0;

	for (int i = 0; i < n; i++)
	{
		int num; cin >> num;
		if (num == 0)
		{
			zeroCnt++;
			continue;
		}
		if (num < 0) neg.push_back(num);
		else pos.push_back(num);
	}
	sort(neg.begin(), neg.end()); int negSize = neg.size();
	sort(pos.begin(), pos.end()); int posSize = pos.size();

	// 가장 작은 음수부터 2개씩 묶기
	int sum = 0;
	int negIdx = 0;
	while (negIdx <= negSize - 2)
	{
		sum += neg[negIdx] * neg[negIdx + 1];
		negIdx += 2;
	}

	// 0의 개수만큼 남아있는 가장 작은 음수부터 제거 (묶기)
	negIdx += zeroCnt;

	// 남은 negatives들은 더하기
	while (negIdx < negSize)
	{
		sum += neg[negIdx++];
	}

	// pos는 큰 수부터 2개씩 묶기
	int posIdx = posSize - 1;
	while (posIdx >= 1)
	{
		// 1은 안 묶음
		if (pos[posIdx - 1] == 1) break;
		sum += pos[posIdx] * pos[posIdx - 1];
		posIdx -= 2;
	}

	// 남은 pos 더하기
	while (posIdx >= 0)
	{
		sum += pos[posIdx--];
	}

	cout << sum;
}