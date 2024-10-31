#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    for (int w : works) pq.push(w);
    
    while (n > 0 && !pq.empty())
    {
        int longest = pq.top(); pq.pop();
        if (longest - 1 != 0) pq.push(longest-1);
        n--;
    }
    
    while (!pq.empty())
    {
        int t = pq.top(); pq.pop();
        answer += (long long)t * t;
    }
    
    return answer;
}