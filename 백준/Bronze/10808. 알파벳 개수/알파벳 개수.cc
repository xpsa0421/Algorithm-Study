#include <iostream>
using namespace std;

int cnt[26];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    for (char c : s)
        cnt[c - 'a']++;
    for (int c : cnt)
        cout << c << ' ';
}
