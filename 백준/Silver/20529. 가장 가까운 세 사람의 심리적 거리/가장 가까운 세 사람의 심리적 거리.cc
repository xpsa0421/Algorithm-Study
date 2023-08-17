#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, unordered_map<string, int>> dict;
int GetDistance(const string& a, const string& b, const string& c);
int GetDistanceTwo(const string& a, const string& b);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	string mbti[16] = { "ESTP", "ESTJ", "ESFP", "ESFJ", "ENTP", "ENTJ", "ENFJ", "ENFP",
		"ISTP", "ISTJ", "ISFP", "ISFJ", "INTP", "INTJ", "INFJ", "INFP" };
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (i == j) dict[mbti[i]][mbti[j]] = 0;
			else dict[mbti[i]][mbti[j]] = GetDistanceTwo(mbti[i], mbti[j]);
		}
	}

	int num_tests = 0;
	cin >> num_tests;

	while (num_tests--)
	{
		unordered_map<string, int> map;

		// collect cases
		int num_cases = 0;
		cin >> num_cases;

		while (num_cases--)
		{
			string mbti;
			cin >> mbti;
			map[mbti]++;
		}
	
		// find distance
		int distance = 1000;
		for (auto iter = map.begin(); iter != map.end(); iter++)
		{
			if (iter->second >= 3)
			{
				distance = 0;
				break;
			}

			for (auto iter_2 = next(iter); iter_2 != map.end(); iter_2++)
			{
				if (iter->second >= 2)
				{
					distance = min(distance, GetDistance(iter->first, iter->first, iter_2->first));
				}
				if (iter_2->second >= 2)
				{
					distance = min(distance, GetDistance(iter->first, iter_2->first, iter_2->first));
				}

				for (auto iter_3 = next(iter_2); iter_3 != map.end(); iter_3++)
				{
					distance = min(distance, GetDistance(iter->first, iter_2->first, iter_3->first));
				}
			}
		}

		cout << distance << "\n";
	}
}

int GetDistance(const string& a, const string& b, const string& c)
{
	return dict[a][b] + dict[a][c] + dict[b][c];
}

int GetDistanceTwo(const string& a, const string& b)
{
	int distance = 0;

	for (int i = 0; i < 4; i++)
	{
		if (a[i] != b[i]) distance++;
	}

	return distance;
}