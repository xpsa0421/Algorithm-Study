#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> numList;
    for (string& s : phone_book)
        numList.insert(s);
    
    for (string& ori : phone_book)
    {
        int len = ori.size();
        string tmp = "";
        for (int i = 0; i < len - 1; i++)
        {
            tmp += ori[i];
            if (numList.find(tmp) != numList.end())
                return false;
        }
    }
    
    return true;
}