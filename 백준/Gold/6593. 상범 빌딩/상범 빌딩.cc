#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos
{
	int l;
	int r;
	int c;

	Pos(int l, int r, int c) : l(l), r(r), c(c) {};
	Pos() : l(0), r(0), c(0) {};
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	while (1)
	{
		int L = 0, R = 0, C = 0;
		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0) break;

		vector<vector<vector<char>>> map(L, vector<vector<char>>(R, vector<char>(C, ' ')));
		vector<vector<vector<bool>>> visited(L, vector<vector<bool>>(R, vector<bool>(C, false)));
		vector<vector<vector<int>>> counts(L, vector<vector<int>>(R, vector<int>(C, 0)));
		Pos start, end;
		for (int l = 0; l < L; l++)
		{
			for (int r = 0; r < R; r++)
			{
				for (int c = 0; c < C; c++)
				{
					cin >> map[l][r][c];
					if (map[l][r][c] == 'S') start = Pos(l, r, c);
					else if (map[l][r][c] == 'E') end = Pos(l, r, c);
				}
			}
		}

		bool escaped = false;
		queue<Pos> to_visit;
		to_visit.push(start);

		while (!to_visit.empty())
		{
			Pos curr = to_visit.front();
			to_visit.pop();

			int l = curr.l, r = curr.r, c = curr.c;
			Pos neighbours[6] = { Pos(l, r, c + 1), Pos(l, r, c - 1), Pos(l, r + 1, c), Pos(l, r - 1, c), Pos(l - 1, r, c), Pos(l + 1, r, c) };

			for (auto [next_l, next_r, next_c] : neighbours)
			{
				if (next_l < 0 || next_l == L || next_r < 0 || next_r == R || next_c < 0 || next_c == C) continue;
				if (visited[next_l][next_r][next_c]) continue;
				if (map[next_l][next_r][next_c] == '#') continue;

				visited[next_l][next_r][next_c] = true;
				to_visit.push(Pos(next_l, next_r, next_c));
				counts[next_l][next_r][next_c] = counts[curr.l][curr.r][curr.c] + 1;
				if (next_l == end.l && next_r == end.r && next_c == end.c)
				{
					escaped = true;
					break;
				}
			}
		}

		if (escaped) cout << "Escaped in " << counts[end.l][end.r][end.c] << " minute(s).\n";
		else cout << "Trapped!\n";
	}
}

