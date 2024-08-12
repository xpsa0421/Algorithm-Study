#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> nums(n, vector<int>(m, 0));
    for (int x = 0; x < n; x++)
    {
        string s;
        cin >> s;
        for (int y = 0; y < m; y++)
        {
            nums[x][y] = s[y] - '0';
        }
    }

    int ans = 1;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            int curNum = nums[x][y];
            int maxSize = min(m - y, n - x);

            for (int size = 1; size < maxSize; size++)
            {
                if (curNum == nums[x][y + size]
                    && curNum == nums[x + size][y]
                    && curNum == nums[x + size][y + size])
                {
                    ans = max(ans, (size+1) * (size+1));
                }
            }
        }
    }

    cout << ans;
}