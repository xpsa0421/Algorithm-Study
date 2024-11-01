#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;

int p[1001];

int find(int a)
{
    if (p[a] < 0) return a;
    else return p[a] = find(p[a]);
}

bool merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b) return false;
    if (p[a] == p[b]) p[a]--;
    if (p[a] < p[b]) p[b] = a;
    else p[a] = b;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    fill_n(p, 1001, -1);

    vector<pair<int, int>> pos(n+1);
    for (int i = 1; i <= n; i++)
    {
        int x, y; cin >> x >> y;
        pos[i] = { x, y };
    }

    int cnt = 0;
    vector<vector<double>> dist(n + 1, vector<double>(n + 1, -1));
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        if (merge(a, b)) cnt++;
        dist[a][b] = dist[b][a] = 0;
    }

    vector<tuple<double, int, int>> edges;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (dist[i][j] != -1) continue;

            int x1 = pos[i].first, x2 = pos[j].first;
            int y1 = pos[i].second, y2 = pos[j].second;
            int dx = x2 - x1, dy = y2 - y1;
            dist[i][j] = sqrt((long long)dx * dx + (long long)dy * dy);
            edges.push_back({ dist[i][j], i, j });
        }
    }

    sort(edges.begin(), edges.end());
    double sum = 0;
    for (auto& [c, a, b] : edges)
    {
        if (!merge(a, b)) continue; // 이미 연결된 그룹

        // 새롭게 연결한 통로
        sum += c;
        cnt++;
        if (cnt == n - 1) break;
    }

    cout << fixed << setprecision(2) << sum;
}
