#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int n = priorities.size();
    vector<int> tmp(priorities.begin(), priorities.end());
    sort(tmp.begin(), tmp.end(), greater<int>());
    queue<int> idxQ;
    for (int i = 0; i < n; i++) idxQ.push(i);
    
    int completed = 0;
    while (completed < n)
    {
        int t = idxQ.front(); idxQ.pop();
        if (priorities[t] == tmp[completed])
        {
            completed++;
            if (t == location)
                return completed;
        }
        else idxQ.push(t);
    }    
}