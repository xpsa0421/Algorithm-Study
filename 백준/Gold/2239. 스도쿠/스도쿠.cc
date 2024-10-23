#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

string sudoku[9];
vector<pair<int,int>> blanks;
bool rowState[9][10];
bool colState[9][10];
bool boxState[3][3][10];
bool ansFound;

void backtracking(int bIdx)
{
	// base condition
	if (bIdx == blanks.size())
	{
		ansFound = true;
		return;
	}

	// Try 1 ~ 9 for the blank at bIdx
	int r = blanks[bIdx].first, c = blanks[bIdx].second;
	for (int i = 1; i <= 9; i++)
	{
		if (rowState[r][i] || colState[c][i] || boxState[r / 3][c / 3][i]) continue;

		sudoku[r][c] = i + '0';
		rowState[r][i] = true; colState[c][i] = true; boxState[r / 3][c / 3][i] = true;
		backtracking(bIdx + 1);

		if (ansFound) return;
		sudoku[r][c] = '0';
		rowState[r][i] = false; colState[c][i] = false; boxState[r / 3][c / 3][i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++)
	{
		cin >> sudoku[i];
		for (int j = 0; j < 9; j++)
		{
			int num = sudoku[i][j] - '0';
			if (num == 0)
				blanks.push_back({i,j});
			else
			{
				rowState[i][num] = true;
				colState[j][num] = true;
				boxState[i / 3][j / 3][num] = true;
			}
		}
	}

	if (!blanks.empty()) backtracking(0);

	for (int i = 0; i < 9; i++)
		cout << sudoku[i] << '\n';
}