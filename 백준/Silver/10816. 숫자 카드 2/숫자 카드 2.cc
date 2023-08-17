#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lower_bound(int target);
int upper_bound(int target);

vector<int> cards;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		cards.push_back(num);
	}
	sort(cards.begin(), cards.end());
	
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		cout << upper_bound(x) - lower_bound(x) << " ";
	}
}

int lower_bound(int target)
{
	int start = 0;
	int end = cards.size();
	int mid;

	while (start < end)
	{
		mid = (start + end) / 2;
		if (cards[mid] >= target)
		{
			end = mid;
		}
		else start = mid + 1;
	}

	return start;
}

int upper_bound(int target)
{
	int start = 0;
	int end = cards.size();
	int mid;

	while (start < end)
	{
		mid = (start + end) / 2;
		if (cards[mid] > target)
		{
			end = mid;
		}
		else start = mid + 1;
	}

	return start;
}