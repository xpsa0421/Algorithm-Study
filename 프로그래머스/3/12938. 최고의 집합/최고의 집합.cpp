#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if (s < n) return {-1};
    
    int half = s / n; int rem = s % n;
    vector<int> answer(n, half);
    for (int i = 0; i < rem; i++)
        answer[n-1-i]++;
    
    return answer;
}