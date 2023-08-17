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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_rows, num_cols, tomato_count = 0, ripe_count = 0, total_days_till_rot = 0;
	cin >> num_cols >> num_rows;

	vector<vector<Tomato>>box(num_rows, vector<Tomato>(num_cols));
	vector<pair<int, int>> init_ripe;
	queue<pair<int, int>> to_visit;

	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			int i;
			cin >> i;
			
			box[r][c] = Tomato(i);
			if (i == 1)
			{
				init_ripe.push_back({ r,c });
				ripe_count++;
			}
			if (i != -1) tomato_count++;
		}
	}

	// 목표지점에서 출발해서 각 위치까지의 days 구하기 BFS
	if (ripe_count != tomato_count) // 처음부터 다 ripe인 경우 pass
	{
		for (auto& tomato : init_ripe) // 시작부터 익은 상태였던 토마토들
		{
			to_visit.push({ tomato.first, tomato.second });
		}

		while (!to_visit.empty())
		{
			int r = to_visit.front().first;
			int c = to_visit.front().second;
			to_visit.pop();

			pair<int, int> can_visit[4] = { {r - 1, c}, {r, c + 1}, {r + 1, c}, {r, c - 1} };
			for (auto& near : can_visit)
			{
				int new_r = near.first;
				int new_c = near.second;

				if (0 <= new_r && new_r < num_rows && 0 <= new_c && new_c < num_cols
					&& box[new_r][new_c].info == 0) // 안 익은 토마토가 있을 때
				{					
					to_visit.push({ new_r, new_c });
					box[new_r][new_c].info = 1; // 익음 처리
					box[new_r][new_c].days_till_rot = box[r][c].days_till_rot + 1;
					ripe_count++;
					total_days_till_rot = max(total_days_till_rot, box[new_r][new_c].days_till_rot);
				}
			}
		}
	}
	
	if (tomato_count == ripe_count) cout << total_days_till_rot;
	else cout << -1;
}