#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

string sudoku[9];
vector<pair<int,int>> blanks;
bool ansFound;

// Is it okay to put num at blank bIdx?
bool isOkaySudoku(int bIdx, char num)
{
	int row = blanks[bIdx].first;
	int col = blanks[bIdx].second;

	// row
	for (int c = 0; c < 9; c++)
		if (sudoku[row][c] == num) return false;

	// column
	for (int r = 0; r < 9; r++)
		if (sudoku[r][col] == num) return false;

	// box
	int rStart = (row / 3) * 3;
	int cStart = (col / 3) * 3;
	for (int dr = 0; dr < 3; dr++)
		for (int dc = 0; dc < 3; dc++)
			if (sudoku[rStart + dr][cStart + dc] == num) return false;

	return true;
}

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
		if (!isOkaySudoku(bIdx, i + '0')) continue;
		sudoku[r][c] = i + '0';
		backtracking(bIdx + 1);
		if (ansFound) return;
		sudoku[r][c] = '0';
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
			if (sudoku[i][j] == '0') blanks.push_back({i,j});
		}
	}

	if (!blanks.empty()) backtracking(0);

	for (int i = 0; i < 9; i++)
		cout << sudoku[i] << '\n';
}