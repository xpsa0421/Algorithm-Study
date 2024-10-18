#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;

	set<int> places;
	for (int i = 1; i <= n; i++)
	{
		int a; cin >> a;
		if (a == 1) places.insert(i);
	}

	int query;
	int pos = 1;
	while (q--)
	{
		cin >> query;
		switch (query)
		{
		case 1:
			int i; cin >> i;
			if (places.find(i) == places.end()) places.insert(i);
			else places.erase(i);
			break;

		case 2:
			int x; cin >> x;
			pos = (pos + x) % n;
			if (pos == 0) pos = n;
			break;

		case 3:
			// 명소가 존재하지 않는 경우
			if (places.empty())
			{
				cout << -1 << '\n';
				break;
			}
			
			// 이미 명소에 있는 경우
			if (places.find(pos) != places.end())
			{
				cout << 0 << '\n';
				break;
			}

			// 명소로 이동해야 하는 경우
			int move = 0;
			auto nextItr = places.upper_bound(pos); // 나보다 높은 숫자의 명소
			if (nextItr == places.end())
			{
				// 없다면 가장 낮은 숫자의 명소
				move = n - pos + *places.begin();
			}
			else
			{
				move = *nextItr - pos;
			}
			cout << move << '\n';
			break;
		}
	}
}
