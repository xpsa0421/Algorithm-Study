#include <iostream>
#include <vector>
using namespace std;

int dp[15][15] = { 0 };
int GetDP(int floor, int room);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	GetDP(14, 14);

	for (int i = 0; i < n; i++)
	{
		int floor, room;
		cin >> floor >> room;
		cout << dp[floor][room] << "\n";
	}
}

// top-down approach
int GetDP(int floor, int room)
{
	if (dp[floor][room]) return dp[floor][room];
	if (room == 0) return 0;
	if (floor == 0)
	{
		dp[floor][room] = room;
		return room;
	}

	return dp[floor][room] = GetDP(floor, room - 1) + GetDP(floor - 1, room);
}