#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

bool is_valid = true;
int match_res[6][3];
void BackTracking(int curr, int other, int depth);
bool AreAllMatchesCovered();

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int res[4] = { 0 };
	for (int test = 0; test < 4; test++)
	{
		is_valid = true;
		memset(match_res, 0, sizeof(match_res));
		for (int c = 0; c < 6; c++)
		{
			for (int k = 0; k < 3; k++)
			{
				cin >> match_res[c][k];
			}				

			// 나라당 도합 5가 아닌 경우
			if (match_res[c][0] + match_res[c][1] + match_res[c][2] != 5)
				is_valid = false;
		}

		if (is_valid)
		{
			is_valid = false;
			BackTracking(0, 1, 0);
		}

		res[test] = is_valid;
	}

	// output
	for (int i = 0; i < 4; i++)
	{
		cout << res[i] << " ";
	}
}

void BackTracking(int curr, int other, int match_count)
{
	// 최종 조건 검사
	if (curr == 5 && match_count == 15)
	{
		is_valid = AreAllMatchesCovered();
		return;
	}

	// 승 - 패
	if (match_res[curr][0] > 0 && match_res[other][2] > 0) 
	{
		match_res[curr][0]--; match_res[other][2]--;
		BackTracking(curr, other + 1, match_count + 1);
		match_res[curr][0]++; match_res[other][2]++;
	}
	// 무 - 무
	if (match_res[curr][1] > 0 && match_res[other][1] > 0) 
	{
		match_res[curr][1]--; match_res[other][1]--;
		BackTracking(curr, other + 1, match_count + 1);
		match_res[curr][1]++; match_res[other][1]++;
	}
	// 패 - 승
	if (match_res[curr][2] > 0 && match_res[other][0] > 0) 
	{
		match_res[curr][2]--; match_res[other][0]--;
		BackTracking(curr, other + 1, match_count + 1);
		match_res[curr][2]++; match_res[other][0]++;
	}

	// 다음 나라 검사
	if (curr < 5)
	{
		BackTracking(curr + 1, curr + 2, match_count);
	}
}

bool AreAllMatchesCovered()
{
	for (int c = 0; c < 6; c++)
	{
		if (match_res[c][0] != 0 || match_res[c][1] != 0 || match_res[c][2] != 0)
			return false;
	}
	return true;
}