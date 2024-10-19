#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int times[10][10];
bool visited[10];
int n, k, minCost = INF;

void solveCost(int cur, int cost)
{
	bool allTraveled = true;
	for (int j = 0; j < n; j++)
	{
		if (visited[j]) continue;
		allTraveled = false;
		visited[j] = true;
		solveCost(j, cost + times[cur][j]);
		visited[j] = false;
	}
	if (allTraveled) minCost = min(minCost, cost);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> times[i][j];

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				times[i][j] = min(times[i][j], times[i][k] + times[k][j]);
	
	visited[k] = true;
	solveCost(k, 0);
	cout << minCost;
}
