#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> weights(n + 1);
    vector<int> values(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> weights[i] >> values[i];
    }

    vector<int> dp(k + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = k; j >= weights[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    cout << dp[k];
}