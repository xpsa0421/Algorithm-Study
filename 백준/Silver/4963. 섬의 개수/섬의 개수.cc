#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

int w, h;
int ans = 0; 
int map[51][51];
bool visited[51][51];
int xOffsets[] = { -1,-1,0,1,1,1,0,-1 };
int yOffsets[] = { 0,1,1,1,0,-1,-1,-1 };

void DFS(int x, int y)
{
    visited[x][y] = true;

    for (int i = 0; i < 8; i++)
    {
        int newX = x + xOffsets[i];
        int newY = y + yOffsets[i];

        if (newX < 0 || newX >= h || newY < 0 || newY >= w) continue;
        if (visited[newX][newY] || map[newX][newY] == 0) continue;

        DFS(newX, newY);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> w >> h;

    while (w != 0)
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
            }
        }

        // Search
        memset(visited, false, sizeof(visited));
        ans = 0;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (!visited[i][j] && map[i][j] == 1)
                {
                    DFS(i, j);
                    ans++;
                }
            }
        }

        cout << ans << '\n';

        cin >> w >> h;
    }
}