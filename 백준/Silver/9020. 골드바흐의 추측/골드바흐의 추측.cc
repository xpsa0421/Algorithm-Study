#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<bool> isPrime(10001, true);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // calculate primes
    isPrime[1] = false;
    for (int i = 2; i < sqrt(10000); i++)
    {
        if (!isPrime[i]) continue;
        for (int j = i + i; j < 10000; j += i)
        {
            isPrime[j] = false;
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        for (int i = n / 2; i >= 2; i--)
        {
            if (!isPrime[i]) continue;
            if (!isPrime[n - i]) continue;

            cout << min(i, n - i) << " " << max(i, n - i) << "\n";
            break;
        }
    }
}