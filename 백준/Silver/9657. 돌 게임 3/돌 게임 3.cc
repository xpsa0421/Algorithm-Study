#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dp[1001];

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    
    // Base case
    dp[1] = true;
    dp[2] = false;
    dp[3] = true;
    dp[4] = true;

    // Solve - DP
    for (int i = 5; i <= n; i++)
    {
        dp[i] = !(dp[i - 1] && dp[i - 3] && dp[i - 4]);
    }

    // Output
    cout << (dp[n] ? "SK" : "CY");}
