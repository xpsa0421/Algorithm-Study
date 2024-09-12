#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, sum = 0;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cin >> m;

    // 오름차순 정렬
    sort(nums.begin(), nums.end());

    int start = 0, end = nums.back();
    while (start <= end)
    {
        sum = 0;
        int mid = (start + end) / 2;

        for (int num : nums) sum += min(num, mid);
        if (sum <= m) start = mid + 1;
        else end = mid - 1;
    }

    cout << end;
}
