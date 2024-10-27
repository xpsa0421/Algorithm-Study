#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

string s;
bool solve(string t)
{
    // Base case
    if (s.size() >= t.size())
    {
        return s == t;
    }
    
    // 뒤에 A 추가
    if (t[t.size() - 1] == 'A')
    {
        string tmp = t;
        tmp.erase(t.size() - 1);
        if (solve(tmp)) return true;
    }
    
    // 뒤에 b 추가 후 뒤집기
    if (t[0] == 'B')
    {
        reverse(t.begin(), t.end());
        t.erase(t.size() - 1);
        if (solve(t)) return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string t;
    cin >> s >> t;
    cout << (solve(t) ? 1 : 0);
}
