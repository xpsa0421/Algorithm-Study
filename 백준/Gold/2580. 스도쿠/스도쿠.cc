#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int sudoku[9][9];
bool rowState[9][10];
bool colState[9][10];
bool boxState[3][3][10];
vector<pair<int, int>> blanks;

bool backtracking(int bIdx)
{
	if (bIdx == blanks.size())
	{
		return true;
	}

	bool isFilled = false;
	int r = blanks[bIdx].first, c = blanks[bIdx].second;
	for (int i = 1; i <= 9; i++)
	{
		if (!rowState[r][i] && !colState[c][i] && !boxState[r / 3][c / 3][i])
		{
			sudoku[r][c] = i;
			rowState[r][i] = colState[c][i] = boxState[r / 3][c / 3][i] = true;
			if (backtracking(bIdx + 1)) return true;
			else rowState[r][i] = colState[c][i] = boxState[r / 3][c / 3][i] = false;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int n;
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			cin >> n;
			sudoku[r][c] = n;
			if (n == 0) blanks.emplace_back(r, c);
			else
			{
				rowState[r][n] = true;
				colState[c][n] = true;
				boxState[r / 3][c / 3][n] = true;
			}
		}
	}

	backtracking(0);

	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			cout << sudoku[r][c] << ' ';
		}
		cout << '\n';
	}
}