#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int h, w; cin >> h >> w;
    vector<int> heights(w);
    for (int i = 0; i < w; i++)
        cin >> heights[i];

    int sum = 0;
    int leftI = 0, rightI = 0;
    int runMax = 0;
    
    while (leftI < w - 1)
    {
        bool hasHigher = false;
        for (int i = leftI + 1; i < w; i++)
        {
            // 가장 높은 높이보다 높거나 같은 높이가 있다면 거기까지
            if (heights[i] > heights[leftI])
            {
                for (int j = leftI + 1; j < i; j++)
                    sum += heights[leftI] - heights[j];
                leftI = i;
                hasHigher = true;
                break;
            }
            // 없다면 남은 높이중 가장 높은 높이까지
            else
            {
                if (heights[i] >= runMax)
                {
                    runMax = heights[i];
                    rightI = i;
                }
            }
        }

        // 더 높은 블록을 찾지 못했다면
        if (!hasHigher)
        {
            for (int j = leftI + 1; j < rightI; j++)
                sum += heights[rightI] - heights[j];
            leftI = rightI;
        }
        runMax = -1;
    }

    cout << sum;
}
