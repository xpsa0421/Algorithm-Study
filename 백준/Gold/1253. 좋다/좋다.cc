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
    sort(nums.begin(), nums.end());

    int good_count = 0;
    for (int k = 0; k < n; k++)
    {
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (i == k)
            {
                i++;
                continue;
            }
            if (j == k) 
            {
                j--;
                continue;
            }

            int sum = nums[i] + nums[j];
            if (sum == nums[k])
            {
                good_count++;
                break;
            }
            else if (sum < nums[k])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
    }

    cout << good_count;
}
