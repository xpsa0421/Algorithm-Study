#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    bool isNeg = false;
    int minNum, maxNum;
    vector<int> nums;
    int cur = 0;
    for (char c : s)
    {
        if (c == ' ')
        {
            int num = (isNeg ? -1 : 1) * cur;
            nums.push_back(num);
            isNeg = false;
            cur = 0;
        }
        else if (c == '-') 
        {
            isNeg = true;
        }
        else
        {
            if (cur == 0) cur = c - '0';
            else cur = cur * 10 + (c - '0');
        }
    }
    int num = (isNeg ? -1 : 1) * cur;
    nums.push_back(num);
    
    minNum = maxNum = nums[0];
    for (int n : nums)
    {
        minNum = min(minNum, n);
        maxNum = max(maxNum, n);
    }
    
    string answer = "" + to_string(minNum) + " " + to_string(maxNum);    
    return answer;
}