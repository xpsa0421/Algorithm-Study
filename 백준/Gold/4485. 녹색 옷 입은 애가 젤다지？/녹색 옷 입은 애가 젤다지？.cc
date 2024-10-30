#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int cost[125][125];
int dist[125][125];

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, 
        greater<tuple<int, int, int>>> pq;

    int t = 1;
    while (true)
    {
        int n; cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> cost[i][j];

        for (int i = 0; i < n; i++)
            fill_n(dist[i], n, 1250);

        dist[0][0] = cost[0][0];
        pq.push({ cost[0][0], 0,0 });

        while (!pq.empty())
        {
            int w, r, c;
            tie(w, r, c) = pq.top(); pq.pop();
            if (dist[r][c] != w) continue;

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nr == n || nc < 0 || nc == n) continue;
                
                int nw = dist[r][c] + cost[nr][nc];
                if (dist[nr][nc] <= nw) continue;
                dist[nr][nc] = nw;
                pq.push({ nw, nr, nc });
            }
        }

        cout << "Problem " << t << ": " << dist[n - 1][n - 1] << '\n';
        t++;
    }
}
