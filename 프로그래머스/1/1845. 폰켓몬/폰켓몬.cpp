#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> set;
    for (int n : nums)
    {
        set.insert(n);
    }
    answer = min(nums.size() / 2, set.size());
    return answer;
}