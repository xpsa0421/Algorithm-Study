#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> stk;
    for (char c : s)
    {
        if (c == '(')
            stk.push(c);
        else
        {
            if (stk.empty())
            {
                answer = false;
                break;
            }
            if (stk.top() == '(')
                stk.pop();
        }
    }
    if (!stk.empty()) answer = false;
    return answer;
}