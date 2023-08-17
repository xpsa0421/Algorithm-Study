#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Tomato
{
	int info = 0;
	int days_till_rot = 0;

	Tomato() { };
	Tomato(int i) : info(i) {};
};

struct Coord
{
	int h = 0; 
	int r = 0;
	int c = 0;
	
	Coord(int h, int r, int c) : r(r), c(c), h(h) {};
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_rows, num_cols, num_boxes, tomato_count = 0, ripe_count = 0, total_days_till_rot = 0;
	cin >> num_cols >> num_rows >> num_boxes;

	vector<vector<vector<Tomato>>>box(num_boxes, vector<vector<Tomato>>(num_rows, vector<Tomato>(num_cols)));
	queue<Coord> to_visit;

	for (int h = 0; h < num_boxes; h++)
	{
		for (int r = 0; r < num_rows; r++)
		{
			for (int c = 0; c < num_cols; c++)
			{
				int i;
				cin >> i;

				box[h][r][c] = Tomato(i);
				if (i == 1)
				{
					to_visit.push(Coord(h,r,c));
					ripe_count++;
				}
				if (i != -1) tomato_count++;
			}
		}
	}
	

	// 목표지점에서 출발해서 각 위치까지의 days 구하기 BFS
	if (ripe_count != tomato_count) // 처음부터 다 ripe인 경우 pass
	{
		while (!to_visit.empty())
		{
			int h = to_visit.front().h;
			int r = to_visit.front().r;
			int c = to_visit.front().c;
			to_visit.pop();

			Coord can_visit[6] = {{h - 1, r, c}, {h + 1, r, c},
									{h, r - 1, c}, {h, r, c + 1}, {h, r + 1, c}, {h, r, c - 1}};

			for (auto& near : can_visit)
			{
				int new_h = near.h;
				int new_r = near.r;
				int new_c = near.c;

				if (0 <= new_h && new_h < num_boxes &&
					0 <= new_r && new_r < num_rows && 
					0 <= new_c && new_c < num_cols
					&& box[new_h][new_r][new_c].info == 0) // 안 익은 토마토가 있을 때
				{
					to_visit.push({ new_h, new_r, new_c });
					box[new_h][new_r][new_c].info = 1; // 익음 처리
					box[new_h][new_r][new_c].days_till_rot = box[h][r][c].days_till_rot + 1;
					ripe_count++;
					total_days_till_rot = max(total_days_till_rot, box[new_h][new_r][new_c].days_till_rot);
				}
			}
		}
	}

	if (tomato_count == ripe_count) cout << total_days_till_rot;
	else cout << -1;
}
