#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> amounts(n);
    for (int i = 0; i < n; i++)
        cin >> amounts[i];

    // 초기 상태
    vector<int> dp(n);
    dp[0] = amounts[0];
    if (n > 1) 
        dp[1] = amounts[0] + amounts[1];
    if (n > 2)
        dp[2] = max(dp[1], max(dp[0] + amounts[2], amounts[1] + amounts[2]));

    // DP 계산
    for (int i = 3; i < n; i++)
    {
        dp[i] = max(dp[i - 1], // i번째 잔을 마시지 않는 경우
            max(dp[i - 2] + amounts[i], // i번째 잔을 마시는 경우 (i-1 잔은 안 마심)
                dp[i - 3] + amounts[i] + amounts[i - 1])); // i번째와 i-1번째 잔을 마시는 경우 (i-2 잔은 안 마심)
    }

    // 최종 결과
    cout << dp[n - 1];
}
