#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name) {
    int n = name.size();
    int answer = 0;

    // 각 문자 변경 횟수 계산
    for (int i = 0; i < n; i++) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
    }

    // 커서 이동 최소화
    int min_move = n - 1; // 기본적으로 오른쪽으로 쭉 가는 경우
    for (int i = 0; i < n; i++) {
        int next = i + 1;
        while (next < n && name[next] == 'A') {
            next++;
        }
        min_move = min(min_move, i + n - next + min(i, n - next));
    }

    answer += min_move;
    return answer;
}
