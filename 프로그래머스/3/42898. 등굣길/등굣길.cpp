#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<bool>> isPuddle(n + 1, vector<bool>(m + 1, false));
    for (const auto& puddle : puddles)
        isPuddle[puddle[1]][puddle[0]] = true;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue; 
            if (isPuddle[i][j]) dp[i][j] = 0;
            else 
            {
                if (i > 1) dp[i][j] += dp[i - 1][j];
                if (j > 1) dp[i][j] += dp[i][j - 1];
                dp[i][j] %= 1000000007; // 모듈로 연산
            }
        }
    }

    return dp[n][m];
}
