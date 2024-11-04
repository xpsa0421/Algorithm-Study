#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int gcdVal;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcdVal;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        gcdVal = gcd(a, b);
        int lcmVal = lcm(a, b);

        cout << lcmVal << ' ' << gcdVal << '\n';
    }
}
