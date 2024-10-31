#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(string number, int k) {
    stack<char> stk;
    for (char digit : number) {
        while (!stk.empty() && stk.top() < digit && k > 0) {
            stk.pop();
            k--;
        }
        stk.push(digit);
    }

    // 스택에 남아있는 문자들을 문자열로 만듭니다.
    string result;
    while (!stk.empty()) {
        result = stk.top() + result;
        stk.pop();
    }
    
    // 남은 제거할 숫자가 있다면 뒤에서 자릅니다.
    if (k > 0) {
        result = result.substr(0, result.size() - k);
    }

    return result;
}
