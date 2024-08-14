#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<tuple<int, int, int>> buses (n);
    for (auto& [s, e, c] : buses)
    {
        cin >> s >> e >> c;
    }
    sort(buses.begin(), buses.end());

    int s = get<0>(buses[0]);
    int e = get<1>(buses[0]);
    int c = get<2>(buses[0]);

    vector<tuple<int, int, int>> newBuses;

    for (int i = 1; i < n; i++)
    {
        int ns = get<0>(buses[i]);
        int ne = get<1>(buses[i]);
        int nc = get<2>(buses[i]);

        if (ns > e)
        {
            // 새로운 노선
            newBuses.push_back(make_tuple(s, e, c));
            s = ns; 
            e = ne;
            c = nc;
        }
        else
        {
            // 겹치는 노선
            c = min(c, nc);
            if (ne > e)
            {
                // 노선 연장
                e = ne;
            }
        }
    }

    newBuses.push_back(make_tuple(s, e, c));
    cout << newBuses.size() << '\n';
    for (auto [s, e, c] : newBuses)
    {
        cout << s << ' ' << e << ' ' << c << '\n';
    }
}