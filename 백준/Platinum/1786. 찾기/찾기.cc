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

	string t, p;
	getline(cin, t);
	getline(cin, p);

	if (p.length() > t.length())
	{
		cout << 0;
		return 0;
	}

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
	vector<int> positions;
	for (int i = 0; i < t.length(); i++)
	{
		while (j > 0 && t[i] != p[j]) j = F[j - 1];
		if (t[i] == p[j]) j++;
		if (j == p.length())
		{
			positions.push_back(i - j + 2);
			j = F[j - 1];
		}
	}

	cout << positions.size() << '\n';
	for (int pos : positions)
	{
		cout << pos << ' ';
	}
}