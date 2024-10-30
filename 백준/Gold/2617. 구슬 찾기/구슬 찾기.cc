#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> adj[100];
int numHeavier[100];
int numLighter[100];
bool visited[100];

void dfs(int root, int v)
{
    visited[v] = true;
    for (int next : adj[v])
    {
        if (visited[next]) continue;
        numLighter[next]++;
        numHeavier[root]++;
        dfs(root, next);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Input
    int n, m;
    cin >> n >> m;

    // Solve
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a); // a > b
    }

    for (int i = 1; i <= n; i++)
    {
        memset(visited, false, sizeof(visited));
        dfs(i, i);
    }

    int ans = 0;
    int half = (n + 1) / 2 - 1;
    for (int i = 1; i <= n; i++)
    {
        if (numLighter[i] > half || numHeavier[i] > half)
            ans++;
    }

    // Output
    cout << ans;
}
