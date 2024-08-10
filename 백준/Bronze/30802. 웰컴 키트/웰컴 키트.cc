#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t, p, total = 0;
    int needed[6];

    cin >> n;
    for (int i = 0; i < 6; i++)
    {
        cin >> needed[i];
        total += needed[i];
    }
    cin >> t >> p;

    int numT = 0, numP = 0, extraP = 0;
    for (int i = 0; i < 6; i++)
    {
        numT += needed[i] / t;
        if (needed[i] % t != 0) numT++;
    }

    numP = total / p;
    extraP += total % p;

    cout << numT << '\n' << numP << ' ' << extraP;
}