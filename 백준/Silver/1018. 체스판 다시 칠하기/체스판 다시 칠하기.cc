#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_REPAINT 1250
vector<string> board;

int RepaintBoard(int x, int y, int min_count, bool start_white);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		board.push_back(s);
	}

	int min_count = MAX_REPAINT;
	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			int new_count = RepaintBoard(i, j, min_count, true);
			min_count = min(new_count, min_count);

			new_count = RepaintBoard(i, j, min_count, false);
			min_count = min(new_count, min_count);
		}
	}

	cout << min_count;

	return 0;
}

int RepaintBoard(int x, int y, int min_count, bool start_white)
{
	int count = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char color = board[x + i][y + j];
			if (color != ((i + j) % 2 == start_white ? 'B' : 'W'))
			{
				count++;
				if (count > min_count) return MAX_REPAINT;
			}
		}
	}

	return count;
}