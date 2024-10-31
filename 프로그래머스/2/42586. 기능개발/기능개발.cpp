#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int n = progresses.size();
    vector<int> times(n,0);
    for (int i = 0; i < n; i++)
    {
        int remain = 100 - progresses[i];
        times[i] = remain / speeds[i];
        if (remain % speeds[i] != 0)
            times[i]++;
    }
    
    int prevTime = times[0];
    int curIdx = 0;
    vector<int> answer = {1};    
    for (int i = 1; i < n; i++)
    {
        // 이전 기능과 함께 배포
        if (times[i] <= prevTime)
        {
            answer[curIdx]++;
        }
        else
        {
            curIdx++;
            prevTime = times[i];
            answer.push_back(1);
        }
    }
    
    return answer;
}