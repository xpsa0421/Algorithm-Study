#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
using namespace std;

int sCounts[26];
int s2Counts[26];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	string s, s2;
	cin >> s;
	n--;

	// 메인 단어의 구성 기록하기
	for (char c : s)
	{
		sCounts[c - 'A']++;
	}

	int ans = 0;
	while (n--)
	{
		cin >> s2;

		// 서브 단어의 구성 기록하기
		memset(s2Counts, 0, sizeof(s2Counts));
		for (char c : s2)
		{
			s2Counts[c - 'A']++;
		}

		// 구성 비교하기
		int diff = 0;
		set<int> diffChars;

		// 1차 검열
		if (s2.length() == s.length() || s2.length() == s.length() - 1 || s2.length() == s.length() + 1)
		{
			// 2차 검열		
			for (int i = 0; i < 26; i++)
			{
				if (sCounts[i] == s2Counts[i]) continue;
				else
				{
					diff += abs(sCounts[i] - s2Counts[i]);
					diffChars.insert(i);
					if (diff > 2) break;
				}
			}

			// 비슷한가?
			if (diff <= 1 || (diff == 2 && diffChars.size() == 2))
				ans++;
		}		
	}

	cout << ans;
}