#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool CutTrees(int height);
void BinarySearch(int start, int end);
int max_height = 0;
long long target = 0;
vector<int> trees;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n >> target;

	for (int i = 0; i < n; i++)
	{
		int h;
		cin >> h;
		trees.push_back(h);
	}

	sort(trees.begin(), trees.end(), greater<>());
	BinarySearch(0, trees[0]);
	cout << max_height;
}

bool CutTrees(int height)
{
	long long curr_length = 0;
	for (int tree : trees)
	{
		curr_length += tree - height;
		if (curr_length >= target)
		{
			return true;
		}
	}
	return false;
}

void BinarySearch(int start, int end)
{
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (CutTrees(mid))
		{
			max_height = max(max_height, mid);
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
}
