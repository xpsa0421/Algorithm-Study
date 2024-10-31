#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<string> operations) {
    int cnt = 0;
    
    deque<int> deq;
    for (string& s : operations)
    {
        char query = s[0];
        int num = stoi(s.substr(2));
        
        if (query == 'I')
        {
            auto it = lower_bound(deq.begin(), deq.end(), num);
            deq.insert(it, num);
        }
        else
        {
            if (deq.size() == 0) continue;
            if (num == 1)
            {
                deq.pop_back();
            }
            else
            {
                deq.pop_front();
            }
        }
    }
    
    if (deq.size() == 0) return {0,0};
    else return {deq.back(), deq.front()};
}