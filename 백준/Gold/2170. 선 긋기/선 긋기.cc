#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<bool> isPrime(10001, true);

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
    sort(lines.begin(), lines.end());

    int start = lines[0].first;
    int end = lines[0].second;
    int sum = 0;

    for (int i = 1; i < n; i++)
    {
        if (lines[i].first > end)
        {
            sum += end - start;
            start = lines[i].first;
            end = lines[i].second;
        }
        else
        {
            if (lines[i].second > end)
            {
                end = lines[i].second;
            }
        }
    }

    sum += end - start;
    cout << sum;
}