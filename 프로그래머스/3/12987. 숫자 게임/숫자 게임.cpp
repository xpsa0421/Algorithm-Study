#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<bool> isUsed(n,false);
    
    int cnt = 0;
    for (int i = 0; i < A.size(); i++)
    {
        auto it = upper_bound(B.begin(), B.end(), A[i]);
        while (it != B.end() && isUsed[(it - B.begin())])
        {
            it++;
        }
        if (it == B.end())
        {
            // 가장 낮은 안 쓴 숫자 사용
            int i = 0;
            while (isUsed[i]) i++;
            isUsed[i] = true;
        }
        else
        {
            cnt++;
            isUsed[(it - B.begin())] = true;
        }
    }
    
    return cnt;
}