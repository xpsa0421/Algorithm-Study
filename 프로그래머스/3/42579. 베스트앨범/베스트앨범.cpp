#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

struct Cmp
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) 
    { 
        if (a.first == b.first) 
            return a.second > b.second;
        return a.first < b.first;
    };  
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    int n = plays.size();
    unordered_map<string,int> playCnt;
    unordered_map<string, priority_queue<pair<int, int>, 
        vector<pair<int, int>>, Cmp>> songsByGenre; // numPlays, idx
    
    // 장르별 재생 횟수 및 노래 저장
    for (int i = 0; i < n; i++)
    {
        playCnt[genres[i]] += plays[i];
        songsByGenre[genres[i]].push({plays[i], i}); 
    }
    
    // 장르별 재생 횟수 내림차순 정렬
    vector<pair<string,int>> vec(playCnt.begin(), playCnt.end());
    sort(vec.begin(), vec.end(), [](pair<string,int>&a, pair<string,int>&b)
         { return a.second > b.second; });
    
    vector<int> answer;
    for (const auto g : vec)
    {
        string genreName = g.first;
        auto& pq = songsByGenre[genreName];
        for (int i = 0; i < 2 && !pq.empty(); i++)
        { 
            answer.push_back(pq.top().second); 
            pq.pop(); 
        }
    }
    
    return answer;
}