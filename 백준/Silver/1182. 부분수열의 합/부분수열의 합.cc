#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nums[20];
int n, s, ans;

void Search(int i, int total)
{
    if (i == n) return;

    // Include this number
    if (total + nums[i] == s) ans++;
    Search(i + 1, total + nums[i]);

    // Not include this number
    Search(i + 1, total);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> nums[i];

    Search(0, 0);
    cout << ans;
}