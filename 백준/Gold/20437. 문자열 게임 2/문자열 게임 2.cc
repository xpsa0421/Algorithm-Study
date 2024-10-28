#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--)
    {
        string w; int k;
        cin >> w >> k;

        vector<int> indices[26] = {};
        for (int i = 0; i < w.size(); i++)
            indices[w[i] - 'a'].push_back(i);

        int minLen = 10001, maxLen = -1;
        for (int i = 0; i < 26; i++)
        {
            if (indices[i].size() < k) continue;
            
            int st = 0, en = k - 1;
            while (en < indices[i].size())
            {
                int len = indices[i][en] - indices[i][st] + 1;
                minLen = min(minLen, len);
                maxLen = max(maxLen, len);
                st++; en++;
            }
        }
        if (maxLen == -1) cout << -1 << '\n';
        else cout << minLen << ' ' << maxLen << '\n';
    }
}
