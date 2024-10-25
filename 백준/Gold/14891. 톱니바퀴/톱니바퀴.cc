#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

string gear[4];

void turn(int idx, int dir)
{
	if (dir == 1) // clockwise
	{
		char last = gear[idx][7];
		gear[idx].erase(7);
		gear[idx] = last + gear[idx];
	}
	else // anti-clockwise
	{
		char first = gear[idx][0];
		gear[idx].erase(0, 1);
		gear[idx] = gear[idx] + first;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// Input
	for (int i = 0; i < 4; i++)
		cin >> gear[i];

	int k; cin >> k;
	vector<pair<int, int>> turns(k);
	for (int i = 0; i < k; i++)
	{
		int idx, dir; 
		cin >> idx >> dir;
		turns[i] = { idx - 1, dir };
	}

	// Solve - Simulation
	int initial[4][2];
	for (auto& [idx, dir] : turns)
	{
		// 맞닿은 부분의 초기 상태
		for (int i = 0; i < 4; i++)
		{
			initial[i][0] = gear[i][6] - '0'; // left
			initial[i][1] = gear[i][2] - '0'; // right
		}

		// 회전
		bool isTurned[4] = { false, false, false, false };
		queue<pair<int, int>> toTurn;
		toTurn.push({ idx, dir });

		while (!toTurn.empty())
		{
			int i, d;
			tie(i, d) = toTurn.front(); toTurn.pop();
			isTurned[i] = true;

			turn(i, d);
			int left = i - 1, right = i + 1;

			// left
			if (left != -1 && !isTurned[left] && initial[i][0] != initial[left][1])
				toTurn.push({ left, -d });

			// right
			if (right != 4 && !isTurned[right] && initial[i][1] != initial[right][0])
				toTurn.push({ right, -d });
		}
	}

	// Output
	int score = 0;
	if (gear[0][0] == '1') score += 1;
	if (gear[1][0] == '1') score += 2;
	if (gear[2][0] == '1') score += 4;
	if (gear[3][0] == '1') score += 8;

	cout << score;
}
