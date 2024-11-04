#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;

    cout << lcm(a, b);
}
