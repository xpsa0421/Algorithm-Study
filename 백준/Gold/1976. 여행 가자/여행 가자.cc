#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    int m; cin >> m;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1,201));
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
        for (int j = 1; j <= n; j++)
        {
            int k; cin >> k;
            if (k == 1) dist[i][j] = 1;
        }
    }

    vector<int> path(m);
    for (int i = 0; i < m; i++)
        cin >> path[i];

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j) continue;

                // 경유지를 통해서 갈 수 없는 경우
                if (dist[i][k] == 201 || dist[k][j] == 201) continue;

                // 경유지를 통하는 게 더 가까운 경우
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    bool isValid = true;
    for (int i = 1; i < m; i++)
    {
        if (dist[path[i - 1]][path[i]] == 201)
        {
            isValid = false;
            break;
        }
    }

    cout << (isValid ? "YES" : "NO");
}
