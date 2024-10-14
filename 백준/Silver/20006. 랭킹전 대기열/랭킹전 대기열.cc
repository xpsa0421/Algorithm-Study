#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_set>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, string>& a, const pair<int, string>& b)
{
	return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int p, m;
	cin >> p >> m;

	int l;
	string n;
	bool entered = false;
	vector<vector<pair<int, string>>> rooms;
	vector<int> lvMid;
	for (int i = 0; i < p; i++)
	{
		entered = false;
		cin >> l >> n;
		
		// 들어갈 수 있는 방이 있는지
		for (int r = 0; r < rooms.size(); r++)
		{
			// 레벨 레인지 확인
			if (lvMid[r] - 10 <= l && lvMid[r] + 10 >= l)
			{
				// 정원 확인
				if (rooms[r].size() < m)
				{
					rooms[r].emplace_back(l, n);
					entered = true;
					break;
				}
			}
		}

		// 방이 없다면?
		if (!entered)
		{
			rooms.emplace_back(vector<pair<int, string>>{ make_pair(l, n) });
			lvMid.push_back(l);
		}
	}

	// 방 정보 출력
	for (auto& r : rooms)
	{
		if (r.size() == m)
		{
			cout << "Started!\n";
		}
		else
		{
			cout << "Waiting!\n";
		}

		// 멤버 정렬 (닉네임 사전순)
		sort(r.begin(), r.end(), cmp);

		for (auto& p : r)
		{
			cout << p.first << ' ' << p.second << '\n';
		}
	}
}