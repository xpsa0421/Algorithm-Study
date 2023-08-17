#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int white = 0;
int blue = 0;

void CutPaper(vector<vector<int>>& papers, int r, int c, int n);
void AddColor(int color);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> colors(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> colors[i][j];
		}
	}

	CutPaper(colors, 0, 0, n);
	cout << white << "\n" << blue;
}

void CutPaper(vector<vector<int>>& papers, int r, int c, int n)
{
	if (n == 1)
	{
		AddColor(papers[r][c]);
		return;
	}
	
	int init_color = papers[r][c];
	for (int i = r; i < r + n; i++)
	{
		for (int j = c; j < c + n; j++)
		{
			if (papers[i][j] != init_color)
			{
				goto cut_needed;
			}
		}
	}
	AddColor(init_color);
	return;
	
cut_needed:
	CutPaper(papers, r, c, n / 2);
	CutPaper(papers, r, c + n / 2, n / 2);
	CutPaper(papers, r + n / 2, c, n / 2);
	CutPaper(papers, r + n / 2, c + n / 2, n / 2);
}

void AddColor(int color)
{
	if (color == 0) white++;
	else blue++;
}