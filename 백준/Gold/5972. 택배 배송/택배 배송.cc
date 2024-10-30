#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c, b });
        adj[b].push_back({ c, a });
    }

    vector<int> dist(n + 1, 50000001);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,1 });
    dist[1] = 0;

    while (!pq.empty())
    {
        int curCost, curIdx;
        tie(curCost, curIdx) = pq.top();
        pq.pop();

        if (dist[curIdx] != curCost) continue;

        for (auto& [weight, nextIdx] : adj[curIdx])
        {
            int nextCost = curCost + weight;
            if (dist[nextIdx] <= nextCost) continue;
            dist[nextIdx] = nextCost;
            pq.push({ nextCost, nextIdx });
        }
    }

    cout << dist[n];
}
