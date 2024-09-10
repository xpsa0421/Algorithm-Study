#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // Sort the lost and reserve arrays
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // Remove students who are both in lost and reserve
    for (auto it = lost.begin(); it != lost.end();) {
        auto pos = find(reserve.begin(), reserve.end(), *it);
        if (pos != reserve.end()) {
            reserve.erase(pos);
            it = lost.erase(it);
        }
        else {
            ++it;
        }
    }

    // Try to lend gym clothes
    for (auto it = lost.begin(); it != lost.end();) {
        auto pos = find(reserve.begin(), reserve.end(), *it - 1);
        if (pos != reserve.end()) {
            reserve.erase(pos);
            it = lost.erase(it);
        }
        else {
            pos = find(reserve.begin(), reserve.end(), *it + 1);
            if (pos != reserve.end()) {
                reserve.erase(pos);
                it = lost.erase(it);
            }
            else {
                ++it;
            }
        }
    }

    return n - lost.size();
}