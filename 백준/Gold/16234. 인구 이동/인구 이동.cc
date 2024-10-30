#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, l, r;
bool visited[50][50];
int numPeople[50][50];
int unionTotal[2500];
vector<pair<int, int>> unions[2500];
int numUnions = 0;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void bfs(int startR, int startC)
{
    vector<pair<int, int>> unionTemp;
    queue<pair<int, int>> toVisit;
    int totalTemp = 0;
    toVisit.push({ startR, startC });
    visited[startR][startC] = true;

    while (!toVisit.empty())
    {
        int curR, curC;
        tie(curR, curC) = toVisit.front(); toVisit.pop();
        totalTemp += numPeople[curR][curC];
        unionTemp.push_back({ curR, curC });

        for (int i = 0; i < 4; i++)
        {
            int nextR = curR + dr[i];
            int nextC = curC + dc[i];

            if (nextR < 0 || nextR == n || nextC < 0 || nextC == n) continue;
            if (visited[nextR][nextC]) continue;
            int diff = abs(numPeople[nextR][nextC] - numPeople[curR][curC]);
            if (diff < l || diff > r) continue;
            
            toVisit.push({ nextR, nextC });
            visited[nextR][nextC] = true;
        }
    }

    if (unionTemp.size() > 1)
    {
        unions[numUnions] = unionTemp;
        unionTotal[numUnions] = totalTemp;
        numUnions++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Input
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> numPeople[i][j];
        }
    }

    // Solve
    int days = 0;
    while (true)
    {
        // 연합 국가 찾기
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                    bfs(i, j);
            }
        }

        // 인구 이동
        if (numUnions == 0) break;
        for (int i = 0; i < numUnions; i++)
        {
            int unionSize = unions[i].size();
            int pplPerCountry = unionTotal[i] / unionSize;
            for (auto& [row, col] : unions[i])
                numPeople[row][col] = pplPerCountry;
        }

        // 다음 이동 준비
        for (int i = 0; i < n; i++)
            fill_n(visited[i], n, false);
        numUnions = 0;
        days++;
    }

    // Output
    cout << days;

    return 0;
}
