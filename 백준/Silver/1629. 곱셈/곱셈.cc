#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a, b, c;
long long Power(int n)
{
    if (n == 0) return 1;
    if (n == 1) return a % c;

    long long k = Power(n / 2) % c;
    if (n % 2 == 0)
        return k * k % c;
    else
        return k * k % c * a % c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> a >> b >> c;
    cout << Power(b);
}