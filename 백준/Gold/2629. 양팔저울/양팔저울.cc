#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int weights[30];
int targets[7];
bool dp[30][40001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> weights[i];
	int t; cin >> t;
	for (int i = 0; i < t; i++) cin >> targets[i];

	int maxWeight = 0;
	for (int i = 0; i < n; i++) maxWeight += weights[i];

	// When considering until weight[i],
	dp[0][weights[0]] = true;
	for (int i = 1; i < n; i++)
	{
		// can mass w be measured?
		for (int w = 1; w <= maxWeight; w++)
		{
			dp[i][w] = dp[i - 1][abs(w - weights[i])] 
				|| dp[i-1][w + weights[i]]
				|| dp[i-1][w];
		}
		dp[i][weights[i]] = true;
	}

	// Query
	for (int i = 0; i < t; i++)
		cout << (dp[n - 1][targets[i]] ? "Y " : "N ");
}