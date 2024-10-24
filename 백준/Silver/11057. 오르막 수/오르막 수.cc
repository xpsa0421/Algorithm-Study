#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][11]; // dp[i][j]: 길이 i(1~N)에 숫자 j(0~9)로 시작하는 오르막 수의 개수

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Input
    int n; cin >> n;
    const int MOD = 10007;

    // Initialisation when n = 1
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;

    // 모든 길이마다
    for (int i = 2; i <= n; i++)
    {
        // 모든 시작 숫자마다
        for (int j = 0; j < 10; j++)
        {
            // 한글자 짧은 오르막 수의 j~9 가짓수 더하기
            for (int k = j; k < 10; k++)
            {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= MOD;
            }
        }
    }

    // Output
    int ans = 0;
    for (int i = 0; i < 10; i++)
        ans += dp[n][i];
    cout << ans % MOD;
}
