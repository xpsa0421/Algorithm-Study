#include <string>
#include <vector>

using namespace std;

vector<int> nums;
int t, answer = 0;

void Find(int idx, int curSum)
{
    // Exit condition
    if (idx == nums.size())
    {
        if (curSum == t) answer++;
        return;
    }
    
    // 더하는 경우
    Find(idx + 1, curSum + nums[idx]);
    
    // 빼는 경우
    Find(idx + 1, curSum - nums[idx]);
}

int solution(vector<int> numbers, int target) {
    nums = numbers;
    t = target;
    Find(0, 0);
    return answer;
}