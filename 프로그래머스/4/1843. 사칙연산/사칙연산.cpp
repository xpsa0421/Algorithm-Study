#include <vector>
#include <string>
using namespace std;

int solution(vector<string> arr)
{
    int n = arr.size() / 2 + 1;
    vector<vector<int>> minDp(n, vector<int>(n,1000 * n + 1));
    vector<vector<int>> maxDp(n, vector<int>(n,-1000 * n - 1));
    
    for (int step = 0; step < n; step++)
    {
        for (int i = 0; i < n - step; i++)
        {
            int j = i + step;
            if (step == 0)
            {
                minDp[i][j] = stoi(arr[i * 2]);
                maxDp[i][j] = stoi(arr[i * 2]);
            }
            else
            {
                for (int k = i; k < j; k++)
                {
                    if (arr[k * 2 + 1] == "+")
                    {
                        minDp[i][j] = min(minDp[i][j], minDp[i][k] + minDp[k+1][j]); // 최소+최소
                        maxDp[i][j] = max(maxDp[i][j], maxDp[i][k] + maxDp[k+1][j]); // 최대+최대
                    }
                    else
                    {
                        minDp[i][j] = min(minDp[i][j], minDp[i][k] - maxDp[k+1][j]); // 최소-최대
                        maxDp[i][j] = max(maxDp[i][j], maxDp[i][k] - minDp[k+1][j]); // 최대-최소
                    }
                }
            }
        }
    }
    
    return maxDp[0][n-1];
}