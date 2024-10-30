#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int p[201];

int find(int a)
{
    if (p[a] < 0) return a;
    return p[a] = find(p[a]);
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
    
    int n; cin >> n;
    int m; cin >> m;

    fill(p, p + 201, -1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int k; cin >> k;
            if (k == 1) merge(i, j);
        }
    }

    vector<int> path(m);
    for (int i = 0; i < m; i++)
        cin >> path[i];

    bool isValid = true;
    for (int i = 1; i < m; i++)
    {
        int a = path[i - 1];
        int b = path[i];
        if (merge(a,b))
        {
            isValid = false;
            break;
        }
    }

    cout << (isValid ? "YES" : "NO");
}
