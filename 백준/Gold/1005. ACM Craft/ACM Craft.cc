#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int constructTimes[1001];
int indegrees[1001];
vector<int> adj[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            indegrees[i] = 0;
        }

        for (int i = 1; i <= n; i++)
            cin >> constructTimes[i];

        for (int i = 0; i < k; i++)
        {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            indegrees[y]++;
        }

        int w; cin >> w;

        vector<int> startTimes(n + 1, 0);
        queue<int> q;
        
        for (int i = 1; i <= n; i++)
        {
            if (indegrees[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int v = q.front(); q.pop();
            int endTime = startTimes[v] + constructTimes[v];
            if (v == w) break;

            for (int next : adj[v])
            {
                // 필요한 전제조건중 가장 늦게 끝나는 시간에 시작해야함
                if (startTimes[next] < endTime)
                    startTimes[next] = endTime;
                if (--indegrees[next] == 0)
                    q.push(next);
            }
        }

        cout << startTimes[w] + constructTimes[w] << '\n';
    }
}
