#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	string s;
	cin >> s;

	// 0과 1의 개수 세기
	int ones = 0, zeros = 0;
	for (char c : s)
	{
		if (c == '0') zeros++;
		else ones++;
	}

	// 지워야 할 개수
	int onesToRemove = ones / 2;
	int zerosToRemove = zeros / 2;

	// 우선 앞에서부터 보이는대로 1을 지우고,
	string s2 = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0') s2 += '0';
		else
		{
			onesToRemove--;
			if (onesToRemove == 0)
			{
				s2 += s.substr(i + 1);
				break;
			}
		}
	}

	// 뒤에서부터 보이는대로 0을 지운다
	string s3 = "";
	for (int i = s2.length() - 1; i >= 0; i--)
	{
		if (s2[i] == '1') s3 = '1' + s3;
		else
		{
			zerosToRemove--;
			if (zerosToRemove == 0)
			{
				s3 = s2.substr(0, i) + s3;
				break;
			}
		}
	}

	cout << s3;
}