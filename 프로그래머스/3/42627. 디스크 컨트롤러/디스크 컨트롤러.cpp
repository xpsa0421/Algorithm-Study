#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    // 작업 요청시점 기준으로 오름차순 정리
    sort(jobs.begin(), jobs.end());

    // 작업 소요시간 기준으로 오름차순 정리할 우선순위 큐
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    int time = 0, ans = 0, i = 0, jobCount = jobs.size();
    while (true)
    {
        // 작업 종료
        if (i == jobCount && pq.empty()) break;

        // 현재 존재하는 작업을 pq에 추가
        while (i < jobCount && jobs[i][0] <= time)
        {
            pq.emplace(jobs[i][0], jobs[i][1]);
            i++;
        }

        // pq에 존재하는 작업을 순서대로 처리
        if (!pq.empty())
        {
            ans += (time - pq.top().first + pq.top().second);
            time += pq.top().second;
            pq.pop();
        }
        // 작업이 없다면 다음 작업 요청 시간으로 건너뜀
        else
        {
            time = jobs[i][0];
        }
    }

    return ans / jobCount;
}