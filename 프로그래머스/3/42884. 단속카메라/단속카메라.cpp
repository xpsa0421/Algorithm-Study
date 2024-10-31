#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {    
    sort(routes.begin(), routes.end());
    int cnt = 1;
    int camPos = routes[0][1];
    int n = routes.size();
    for (int i = 1; i < n; i++)
    {
        if (routes[i][1] <= camPos)
            camPos = routes[i][1];
        else if (routes[i][0] > camPos)
        {
            cnt++;
            camPos = routes[i][1];
        }
    }
    return cnt;
}