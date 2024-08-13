#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<bool> isPrime(246913, true);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // calculate primes
    isPrime[1] = false;
    for (int i = 2; i <= sqrt(246912); i++)
    {
        if (!isPrime[i]) continue;

        for (int j = i + i; j <= 246912; j += i)
        {
            isPrime[j] = false;
        }
    }

    int n;
    cin >> n;

    while (n != 0)
    {
        int ans = 0;
        for (int i = n + 1; i <= 2 * n; i++)
        {
            if (isPrime[i]) ans++;
        }

        cout << ans << '\n';
        cin >> n;
    }
}