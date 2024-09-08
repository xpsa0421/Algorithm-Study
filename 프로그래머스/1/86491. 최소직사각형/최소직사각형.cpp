#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int wMax = 0, hMax = 0;
    
    for (int i = 0; i < sizes.size(); i++)
    {
        // 더 긴 부분을 가로로 지정    
        // 더 짧은 부분은 세로
        if (sizes[i][0] > sizes[i][1])
        {
            wMax = max(wMax, sizes[i][0]);
            hMax = max(hMax, sizes[i][1]);
        }
        else
        {
            wMax = max(wMax, sizes[i][1]);
            hMax = max(hMax, sizes[i][0]);
        }
    }
    
    return wMax * hMax;
}