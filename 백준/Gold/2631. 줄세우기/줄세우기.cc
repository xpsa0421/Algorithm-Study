#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> temp;
    temp.push_back(nums[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (temp.back() < nums[i])
        {
            temp.push_back(nums[i]);
            len++;
        }
        else
        {
            auto it = upper_bound(temp.begin(), temp.end(), nums[i]);
            *it = nums[i];
        }
    }

    cout << n - len;
}
