#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	string s, k;
	cin >> s >> k;

	// 실패 함수
	vector<int> F(k.length());
	int j = 0;
	for (int i = 1; i < k.length(); i++)
	{
		while (j > 0 && k[i] != k[j]) j = F[j - 1];
		if (k[i] == k[j]) F[i] = ++j;
	}

	// 문자열 비교
	j = 0;
	for (int i = 0; i < s.length(); i++)
	{
		// 숫자라면 스킵
		if (s[i] >= '0' && s[i] <= '9') continue;

		// 문자라면 비교
		while (j > 0 && s[i] != k[j]) j = F[j - 1];
		if (s[i] == k[j]) j++;
		if (j == k.length())
		{
			cout << 1;
			return 0;
		}
	}
	cout << 0;
}