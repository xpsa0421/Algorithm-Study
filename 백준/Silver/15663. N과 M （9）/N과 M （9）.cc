#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
int nums[8];
int cur[8];
bool visited[8];

void DFS(int len)
{
	if (len == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << cur[i] << " ";
		}
		cout << '\n';
		return;
	}

	int prev = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i] && prev != nums[i])
		{
			cur[len] = prev = nums[i];
			visited[i] = true;
			DFS(len + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	sort(nums, nums + n);

	DFS(0);
}