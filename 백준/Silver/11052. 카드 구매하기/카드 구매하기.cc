#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int costs[1001];
int dp[1001]; // dp[i]: i개의 카드를 구매하는 최댓값

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> costs[i];

    dp[1] = costs[1];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], costs[j] + dp[i - j]);
        }
    }

    cout << dp[n];
}
