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
    
    int num = n, ans = 0;

    do
    {
        int left = num / 10;
        int right = num % 10;
        int sum = left + right;
        num = right * 10 + sum % 10;
        ans++;
    } while (num != n);

    cout << ans;
}