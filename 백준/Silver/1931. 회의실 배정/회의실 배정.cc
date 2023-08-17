#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int meeting_idx = 0;

struct Meeting
{
	int idx = 0;
	int start = 0;
	int end = 0;
	
	Meeting(int start, int end) : idx(meeting_idx++), start(start), end(end) {};
	Meeting(int start) : start(start) {};
	bool operator<(const Meeting& other)
	{
		return this->start != other.start ? this->start < other.start : this->end < other.end;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Meeting> meetings;
	vector<bool> meeting_done(n, false);

	while (n--)
	{
		int start, end;
		cin >> start >> end;
		meetings.push_back(Meeting(start, end));
	}
	sort(meetings.begin(), meetings.end());

	int curr_time = 0;
	int meeting_count = 0;
	int min_start = -1;

	while (1)
	{
		int min_duration = pow(2,31) - 1;
		int min_idx = -1;
		
		auto iter = lower_bound(meetings.begin(), meetings.end(), Meeting(curr_time));
		
		while (iter != meetings.end())
		{
			if (iter->start - curr_time > min_duration) break;
			if (iter->end - curr_time <= min_duration)
			{
				if (meeting_done[iter->idx])
				{
					iter++;
					continue;
				}
				
				if (iter->end - curr_time == min_duration)
				{
					if (iter->start <= min_start)
					{
						min_start = iter->start;
						min_idx = iter->idx;
					}
				}
				else
				{
					min_start = iter->start;
					min_idx = iter->idx;
					min_duration = iter->end - curr_time;
				}				
			}
			iter++;
		}

		if (min_idx == -1) break; // unchanged
		
		meeting_count++;
		curr_time += min_duration;
		meeting_done[min_idx] = true;
	}

	cout << meeting_count;
}
