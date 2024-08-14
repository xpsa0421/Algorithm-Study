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

    vector<pair<int, int>> lines(n);
    for (auto& [s, e] : lines)
    {
        cin >> s >> e;
    }

    long long sum = 0;
    long long s = lines[0].first;
    long long e = lines[0].second;

    for (int i = 1; i < n; i++)
    {
        if (lines[i].first > e)
        {
            sum += e - s;
            s = lines[i].first;
            e = lines[i].second;
        }
        else
        {
            if (lines[i].second > e)
            {
                e = lines[i].second;
            }
        }
    }

    sum += e - s;
    cout << sum;
}