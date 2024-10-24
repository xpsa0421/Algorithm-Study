#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1000001]; // dp[i]: 크기가 i인 2진 수열의 가짓수

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    // Base case
    dp[1] = 1;
    dp[2] = 2;

    // Solve - DP
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;

    // Output
    cout << dp[n];
}
