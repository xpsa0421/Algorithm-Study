#include <string>
#include <vector>
#include <queue>
using namespace std;

int len;
bool canConvert(string& a, string& b)
{
    int diff = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[i] != b[i])
        {
            if (++diff > 1) return false;
        }
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    len = begin.size();
    vector<string> tmp = {begin};
    tmp.insert(tmp.end(), words.begin(), words.end());
    
    int n = tmp.size();
    vector<int> depth(n, -1);
    queue<int> toVisit;
    toVisit.push(0);
    depth[0] = 0;
    
    while (!toVisit.empty())
    {
        int v = toVisit.front(); toVisit.pop();
        
        for (int i = 1; i < n; i++)
        {
            if (depth[i] == -1 && canConvert(tmp[v], tmp[i]))
            {
                depth[i] = depth[v] + 1;
                if (tmp[i] == target) return depth[i];
                toVisit.push(i);                
            }
        }
    }
    
    return 0; 
}