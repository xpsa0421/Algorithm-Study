#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int curPoints[100];

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> minPoints(n, 1);
    for (int i = 0; i < n; i++)
    {
        int p, l;
        cin >> p >> l;
        
        for (int j = 0; j < p; j++) cin >> curPoints[j];
        sort(curPoints, curPoints + p, greater<int>());
        if (p >= l) minPoints[i] = curPoints[l - 1];
    }

    sort(minPoints.begin(), minPoints.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (m < minPoints[i]) break;
        
        ans++;
        m -= minPoints[i];
    }

    cout << ans;
}