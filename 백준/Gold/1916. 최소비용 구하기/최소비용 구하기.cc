#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> paths;
vector<bool> visited;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    paths.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        paths[start].push_back(make_pair(end, cost));
    }

    int start, end;
    cin >> start >> end;

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // < cost, location >
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int current = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        if (current == end)
        {
            std::cout << distance;
            break;
        }
        if (visited[current]) continue;
        visited[current] = true;

        for (pair<int, int> next : paths[current])
        {
            if (!visited[next.first])
                pq.push(make_pair(distance + next.second, next.first));
        }
    }
}