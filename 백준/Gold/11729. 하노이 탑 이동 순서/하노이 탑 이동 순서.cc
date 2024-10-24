#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

int k;
vector<pair<int, int>> moves;

void hanoi(int n, int source, int target, int auxilary)
{
	// base case: one disk
	if (n == 1)
	{
		moves.push_back({ source, target });
		k++;
		return;
	}

	// use auxilary tower to move disks
	hanoi(n - 1, source, auxilary, target);
	moves.push_back({ source, target }); k++;
	hanoi(n - 1, auxilary, target, source);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	hanoi(n, 1, 3, 2);

	cout << k << '\n';
	for (auto& [source, target] : moves)
		cout << source << ' ' << target << '\n';
}