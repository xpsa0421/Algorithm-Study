#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct Date
{
	int month;
	int date;
	
	Date(int m, int d) : month(m), date(d) {}
	bool operator<(const Date& other) const
	{
		if (month == other.month)
			return date < other.date;
		else return month < other.month;
	}
	bool operator>(const Date& other) const {
		if (month == other.month)
			return date > other.date;
		return month > other.month;
	}
	bool operator==(const Date& other) const {
		return month == other.month && date == other.date;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<pair<Date, Date>> flowers;
	flowers.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int stM, stD, enM, enD;
		cin >> stM >> stD >> enM >> enD;
		flowers.push_back({ Date(stM, stD), Date(enM, enD)});
	}
	sort(flowers.begin(), flowers.end());

	int cnt = 0;
	Date currentEnd(3, 1);
	Date end(11, 30);
	int prevIdx = -1, curIdx = 0;

	while (currentEnd < end || currentEnd == end)
	{
		Date bestEnd(0, 0); // 가장 나중에 지는 꽃의 날짜
		bool isFound = false;

		for (int i = 0; i < n; i++)
		{
			auto flower = flowers[i];
			if ((flower.first < currentEnd || flower.first == currentEnd)// 현재 날짜 이전에 피고
				&& flower.second > bestEnd) // 가장 늦게 지는 꽃
			{
				bestEnd = flower.second;
				isFound = true;
				curIdx = i;
			}
		}
		if (isFound)
		{
			if (curIdx == prevIdx) break;
			prevIdx = curIdx;
			cnt++;
			currentEnd = bestEnd;
		}
		else break;
	}

	if (currentEnd > end) cout << cnt;
	else cout << 0;
}