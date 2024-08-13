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

    while (n != 0)
    {
        vector<bool> isPrime(2 * n + 1, true);
        isPrime[1] = false;

        for (int i = 2; i <= sqrt(2 * n); i++)
        {
            if (!isPrime[i]) continue;

            for (int j = i + i; j <= 2 * n; j += i)
            {
                isPrime[j] = false;
            }
        }

        int ans = 0;
        for (int i = n + 1; i <= 2 * n; i++)
        {
            if (isPrime[i]) ans++;
        }

        cout << ans << '\n';
        cin >> n;
    }
}