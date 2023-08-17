#include <iostream>
#include <vector>
using namespace std;

long long dp[101] = { 0 };
void GetDP(int n);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int test_cases, max_n = 0;
	cin >> test_cases;
	vector<int> enquiries(test_cases);

	for (int i = 0; i < test_cases; i++)
	{
		cin >> enquiries[i];
		max_n = max(max_n, enquiries[i]);
	}

	GetDP(max_n);
	for (auto& n : enquiries)
	{
		cout << dp[n] << "\n";
	}
}

void GetDP(int n)
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		if (i == 79)
		{
			int dd = 2;
		}
		dp[i] = dp[i - 2] + dp[i - 3];
	}
}