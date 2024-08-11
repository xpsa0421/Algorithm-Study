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

    string str;
    int ansNum;
    for (int i = 0; i < 3; i++)
    {
        cin >> str;
        if (isdigit(str[0]))
        {
            ansNum = stoi(str) + (3 - i);
        }
    }

    string ansStr = "";
    if (ansNum % 3 == 0) ansStr += "Fizz";
    if (ansNum % 5 == 0) ansStr += "Buzz";

    if (ansStr.compare("") == 0) cout << ansNum;
    else cout << ansStr;
}