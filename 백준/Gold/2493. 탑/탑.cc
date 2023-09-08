#include <iostream>
#include <stack>
#include <vector>
#include <set>
using namespace std;

struct Tower
{
	int index = 0;
	int height = 0;
	
	Tower(int i, int h) : index(i), height(h) {};
	bool operator < (const Tower& other) const
	{
		return this->height < other.height;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> heights(n, 0);
	stack<Tower> towers;
	for (int i = 0; i < n; i++)
	{
		int height;
		cin >> height;
		towers.push(Tower(i + 1, height));
	}
	
	vector<int> res(n, 0);
	set<Tower> todo;
	Tower curr = towers.top();
	towers.pop();

	while (!towers.empty())
	{
		Tower comp = towers.top();

		// 아직 수신되지 못한 타워 확인
		for (auto iter = todo.begin(); iter != todo.end();)
		{
			if (iter->height < comp.height)
			{
				res[iter->index - 1] = comp.index;
				iter = todo.erase(iter);
			}
			else
			{
				break;
			}
		}

		if (comp.height > curr.height)
		{
			// 바로 다음 타워에서 수신한 경우
			res[curr.index - 1] = comp.index;
		}
		else
		{
			// 바로 다음 타워에서 수신하지 못한 경우
			todo.insert(curr);
		}

		curr = comp;
		towers.pop();
	}

	for (int i : res)
	{
		cout << i << " ";
	}
}