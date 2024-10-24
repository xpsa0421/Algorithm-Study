#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vips;
int dp[41];

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Input
    int n, m;
    cin >> n >> m;
    vips.resize(m);
    for (int i = 0; i < m; i++)
        cin >> vips[i];

    // Initialisation
    dp[0] = 1; dp[1] = 1; dp[2] = 2;

    // Solve - DP
    // dp[i-1] (자리를 바꾸지 않는 경우) + dp[i-2] (자리를 바꾸는 경우)
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // vip
    int ans = 1, st = 0;
    for (int i = 0; i < m; i++)
    {
        int en = vips[i];
        ans *= dp[en - st - 1];
        st = en;
    }
    ans *= dp[n - st];

    // Output
    cout << ans;
}
