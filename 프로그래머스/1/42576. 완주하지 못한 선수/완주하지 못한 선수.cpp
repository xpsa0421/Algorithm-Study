#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> counts;
    for (auto p : participant)
    {
        counts[p]++;
    }

    for (auto c : completion)
    {
        counts[c]--;
    }

    for (auto c : counts)
    {
        if (c.second == 1)
        {
            answer = c.first;
            break;
        }
    }

    return answer;
}