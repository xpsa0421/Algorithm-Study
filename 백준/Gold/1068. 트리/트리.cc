#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int n = 0;
	cin >> n;

	// 각 노드마다 최대 두 개의 자식 노드 인덱스를 저장
	vector<vector<int>> children(n);

	for (int i = 0; i < n; i++)
	{
		int parent = -1;
		cin >> parent;

		if (parent != -1)
		{
			children[parent].push_back(i);
		}
	}

	// 노드 삭제
	vector<bool> deleted(n, false);
	int delete_idx = -1;
	cin >> delete_idx;
	queue<int> to_delete;
	to_delete.push(delete_idx);

	while (!to_delete.empty())
	{
		int parent = to_delete.front();
		to_delete.pop();
		deleted[parent] = true;

		for (int i = 0; i < children[parent].size(); i++)
		{
			to_delete.push(children[parent][i]);
			children[parent][i] = -1;
		}
	}

	// 리프노드 검사
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (deleted[i]) continue;

		bool is_leafnode = true;
		for (int child : children[i])
		{
			if (deleted[child]) continue;
			if (child != -1)
			{
				is_leafnode = false;
				break;
			}
		}
		if (children[i].empty() || is_leafnode) count++;
	}

	cout << count;
}