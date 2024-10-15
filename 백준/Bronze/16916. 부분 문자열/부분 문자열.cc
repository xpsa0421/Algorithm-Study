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

	// P가 S의 부분 문자열인가?
	string s, p;
	cin >> s >> p;

	// 실패 함수
	vector<int> F(p.length(), 0);
	int j = 0;
	for (int i = 1; i < p.length(); i++)
	{
		while (j > 0 && p[i] != p[j]) j = F[j - 1];
		if (p[i] == p[j]) F[i] = ++j;
	}

	// 문자열 검사
	j = 0;
	for (int i = 0; i < s.length(); i++)
	{
		while (j > 0 && s[i] != p[j]) j = F[j - 1];
		if (s[i] == p[j]) j++;
		if (j == p.length())
		{
			cout << 1;
			return 0;
		}
	}
	cout << 0;
}