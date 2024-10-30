#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        string s; 
        cin >> s;

        if (s == "end") break;

        int oCnt = 0, xCnt = 0;
        for (char c : s) {
            if (c == 'O') oCnt++;
            else if (c == 'X') xCnt++;
        }

        bool xWin = false, oWin = false;

        // 가로 빙고
        for (int i = 0; i < 3; ++i) {
            if (s[3*i] == s[3*i+1] && s[3*i+1] == s[3*i+2]) {
                if (s[3*i] == 'X') xWin = true;
                if (s[3*i] == 'O') oWin = true;
            }
        }

        // 세로 빙고
        for (int i = 0; i < 3; ++i) {
            if (s[i] == s[i+3] && s[i+3] == s[i+6]) {
                if (s[i] == 'X') xWin = true;
                if (s[i] == 'O') oWin = true;
            }
        }

        // 대각선 빙고
        if ((s[0] == s[4] && s[4] == s[8]) || (s[2] == s[4] && s[4] == s[6])) {
            if (s[4] == 'X') xWin = true;
            if (s[4] == 'O') oWin = true;
        }

        // X는 O보다 하나 많거나 같아야 함
        bool valid = (xCnt == oCnt + 1 || xCnt == oCnt);

        // X와 O가 동시에 이길 수 없음
        if (xWin && oWin) valid = false;
        
        // X가 이기면 X는 O보다 하나 더 많아야 함
        if (xWin && xCnt != oCnt + 1) valid = false;

        // O가 이기면 X와 O의 개수가 같아야 함
        if (oWin && xCnt != oCnt) valid = false;

        // 게임판이 가득 찼는지 확인
        if (!xWin && !oWin && xCnt + oCnt != 9) valid = false;

        cout << (valid ? "valid" : "invalid") << "\n";
    }

    return 0;
}
