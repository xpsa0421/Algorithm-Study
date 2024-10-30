#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

void toggle(char& c)
{
    if (c == '1') c = '0';
    else c = '1';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Input
    int n; cin >> n;
    string ori; cin >> ori;
    string target; cin >> target;

    // Solve - Greedy
    // Case 1: Toggle first
    int ansA = 1; string a = ori + "-";
    toggle(a[0]); toggle(a[1]);
    for (int i = 1; i < n; i++)
    {
        if (target[i - 1] != a[i - 1])
        {
            toggle(a[i - 1]);
            toggle(a[i]);
            toggle(a[i + 1]);
            ansA++;
        }
    }
    if (a[n - 1] != target[n - 1]) ansA = 100001;

    // Case 2: No toggle
    int ansB = 0; a = ori + "-";
    for (int i = 1; i < n; i++)
    {
        if (target[i - 1] != a[i - 1])
        {
            toggle(a[i - 1]);
            toggle(a[i]);
            toggle(a[i + 1]);
            ansB++;
        }
    }
    if (a[n - 1] != target[n - 1]) ansB = 100001;

    if (ansA == 100001 && ansB == 100001)
        cout << -1;
    else cout << (ansA < ansB ? ansA : ansB);
}
