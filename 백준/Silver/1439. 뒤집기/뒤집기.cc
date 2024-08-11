#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int numOnes = 0, numZeros = 0;
    bool prevZero = s[0] == '0';
    for (char c : s)
    {
        if (c == '0')
        {
            if (!prevZero) numOnes++;
            prevZero = true;
        }
        else
        {
            if (prevZero) numZeros++;
            prevZero = false;
        }
    }
    if (prevZero) numZeros++; else numOnes++;

    cout << min(numZeros, numOnes);
}