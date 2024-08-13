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
    vector<vector<int>> friends(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    queue<int> toVisit;
    vector<int> visited(n+1, false);
    vector<int> depth(n + 1, 0);
    int ans = 0;

    toVisit.push(1);
    visited[1] = true;

    while (!toVisit.empty())
    {
        int cur = toVisit.front();
        toVisit.pop();

        for (int f : friends[cur])
        {
            if (!visited[f])
            {
                visited[f] = true;
                depth[f] = depth[cur] + 1;
                ans++;
                if (depth[f] < 2) toVisit.push(f);
            }
        }
    }

    cout << ans;
}