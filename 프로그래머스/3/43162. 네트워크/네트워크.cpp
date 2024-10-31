#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> computers) 
{
    int cnt = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (visited[i]) continue;
        cnt++;
        
        queue<int> toVisit;
        toVisit.push(i);
        
        while (!toVisit.empty())
        {
            int cur = toVisit.front(); toVisit.pop();
            visited[cur] = true;
            
            for (int j = 0; j < n; j++)
            {
                if (computers[cur][j] == 1 && !visited[j])
                {
                    visited[j] = true;
                    toVisit.push(j);
                }
            }
        }
    }
    return cnt;
}