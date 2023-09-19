#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int size = 0;
	cin >> size;

	vector<vector<int>> nums(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			int n = 0;
			cin >> n;
			nums[i].push_back(n);
		}
	}

	// solve
	struct Node
	{
		int dp = -1;
		int parent_idx = -1;
		Node() {};
		Node(int dp, int idx) : dp(dp), parent_idx(idx) {};
	};

	// initialise dp nodes
	vector<vector<Node>> nodes(size);
	nodes[0].push_back(Node(nums[0][0], -1));
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			nodes[i].push_back(Node());
		}
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			// update left diagonal child
			if (nodes[i + 1][j].dp < nodes[i][j].dp + nums[i + 1][j])
			{
				nodes[i + 1][j].dp = nodes[i][j].dp + nums[i + 1][j];
				nodes[i + 1][j].parent_idx = j;
			}

			// update right diagonal child
			if (nodes[i + 1][j + 1].dp < nodes[i][j].dp + nums[i + 1][j + 1])
			{
				nodes[i + 1][j + 1].dp = nodes[i][j].dp + nums[i + 1][j + 1];
				nodes[i + 1][j + 1].parent_idx = j;
			}
		}
	}

	int best_dp = -1;
	for (int i = 0; i < size; i++)
	{
		if (nodes[size - 1][i].dp > best_dp)
		{
			best_dp = nodes[size - 1][i].dp;
		}
	}

	// output
	cout << best_dp;
}