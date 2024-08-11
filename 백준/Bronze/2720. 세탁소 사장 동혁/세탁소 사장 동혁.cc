#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int target;
        cin >> target;

        int ans[4];
        int prices[] = { 25, 10, 5, 1 };

        for (int i = 0; i < 4; i++)
        {
            ans[i] = target / prices[i];
            target %= prices[i];
        }

        for (int answer : ans) cout << answer << ' ';
        cout << '\n';
    }
}