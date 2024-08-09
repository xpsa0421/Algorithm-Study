#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;    

    // Solve
    int nums[3];
    int maxDP[3];
    int minDP[3];

    for (int i = 0; i < 3; i++)
    {
        cin >> maxDP[i];
        minDP[i] = maxDP[i];
    }
    
    for (int i = 1; i < n; i++)
    {
        cin >> nums[0];
        cin >> nums[1];
        cin >> nums[2];

        int leftMax = max(maxDP[0], maxDP[1]);
        int leftMin = min(minDP[0], minDP[1]);
        int rightMax = max(maxDP[1], maxDP[2]);
        int rightMin = min(minDP[1], minDP[2]);
        int midMax = max(leftMax, rightMax);
        int midMin = min(leftMin, rightMin);

        maxDP[0] = nums[0] + leftMax;
        minDP[0] = nums[0] + leftMin;

        maxDP[1] = nums[1] + midMax;
        minDP[1] = nums[1] + midMin;

        maxDP[2] = nums[2] + rightMax;
        minDP[2] = nums[2] + rightMin;
    }

    // Answer
    cout << max(max(maxDP[0], maxDP[1]), maxDP[2]) << " ";
    cout << min(min(minDP[0], minDP[1]), minDP[2]);
}