#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

vector<string> results[10];

int oper(int prevSum, char op, int cur)
{
    if (op == '+')
        return prevSum + cur;
    if (op == '-')
        return prevSum - cur;
    if (op == '#')
        return cur;
}

bool isZero(string s)
{
    int cur = 0, sum = 0;
    char prevOp = '#';
    bool isPrevSpace = false;

    for (char c : s)
    {
        if (c == '+')
        {
            sum = oper(sum, prevOp, cur);
            prevOp = '+';
            cur = 0;
        }
        else if (c == '-')
        {
            sum = oper(sum, prevOp, cur);
            prevOp = '-';
            cur = 0;
        }
        else if (c == ' ')
        {
            isPrevSpace = true;
        }
        else
        {
            if (isPrevSpace)
            {
                cur = cur * 10 + (c - '0');
                isPrevSpace = false;
            }
            else cur = c - '0';
        }
    }
    sum = oper(sum, prevOp, cur);

    return sum == 0;
}

// ASCII: ' ' -> + -> -
void solve(int i, string s)
{
    // Base case
    if (i > 3)
    {
        if (isZero(s)) results[i-1].push_back(s);
        if (i == 10) return;
    }

    // Other cases
    solve(i + 1, s + " " + to_string(i));
    solve(i + 1, s + "+" + to_string(i));
    solve(i + 1, s + "-" + to_string(i));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve(2, "1");
    
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        for (auto s : results[n])
            cout << s << '\n';
        cout << '\n';
    }
}
