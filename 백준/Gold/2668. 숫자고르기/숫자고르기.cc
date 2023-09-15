#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int nums[101];
bool visited[101];
vector<int> valid_nums;
int n = 0;

void DFS(int start, int curr)
{
	if (visited[curr])
	{
		if (curr == start)
		{
			valid_nums.push_back(start);
		}
		return;		
	}
	else
	{
		visited[curr] = true;
		DFS(start, nums[curr]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
	}

	// solve
	for (int i = 1; i <= n; i++)
	{
		memset(visited, false, sizeof(visited));
		DFS(i, i);
	}
	sort(valid_nums.begin(), valid_nums.end());

	// output
	cout << valid_nums.size() << "\n";
	for (int i : valid_nums)
	{
		cout << i << "\n";
	}
}