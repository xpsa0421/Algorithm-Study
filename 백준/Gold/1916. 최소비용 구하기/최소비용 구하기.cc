#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> paths;
vector<int> minDists;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    minDists.resize(n + 1, 100000000);
    paths.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        paths[start].push_back(make_pair(end, cost));
    }

    int start, end;
    cin >> start >> end;

    minDists[start] = 0;
    priority_queue<pair<int, int>> pq; // < cost, location >
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int current = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        if (minDists[current] < distance) continue;

        for (int i = 0; i < paths[current].size(); i++)
        {
            int next = paths[current][i].first;
            int nextDist = distance + paths[current][i].second;

            if (nextDist < minDists[next])
            {
                minDists[next] = nextDist;
                pq.push(make_pair(nextDist, next));
            }
        }
    }

    cout << minDists[end];
}