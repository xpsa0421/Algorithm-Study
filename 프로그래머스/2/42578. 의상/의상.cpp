#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string,int> typeCnt;
    for (auto c : clothes)
        typeCnt[c[1]]++;
    
    int ans = 1;
    for (auto&[type,cnt] : typeCnt)
        ans *= cnt + 1;
    
    return ans - 1;
}